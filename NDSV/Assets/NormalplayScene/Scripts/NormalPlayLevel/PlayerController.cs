using UnityEngine;
using System.Collections;
using System.Collections.Generic;


public class PlayerController : MonoBehaviour {


    public float moveTime = 0.1f;// Take in seconds
    public LayerMask blockingLayer;//The layer which checks collision of trees , soldier , general
  

    private AudioClip moveSound1, moveSound2;
    private Rigidbody2D playerRigidbody;
    private BoxCollider2D playerCollider;
    private float inverseMoveTime;
    private Animator playerAnimator;

	// Use this for initialization
	void Start () 
    {
        playerRigidbody = GetComponent<Rigidbody2D>();

        playerCollider = GetComponent<BoxCollider2D>();
        //Disable the box collider first
       


        //By storing the reciprocal of the move time we can use it by multiplying instead of dividing, this is more efficient.
        inverseMoveTime = 1f / moveTime;

        playerAnimator = GetComponent<Animator>();

        moveSound1 = SoundManager.instance.playerMoveSound1;
        moveSound2 = SoundManager.instance.playerMoveSound2;
       
	
	}
	
	// Update is called once per frame
	private void Update () 
    {
        
        if (GameManager.instance.playerStartConversation || GameManager.instance.pauseGame)
        {
            //Disable this script , the player cant move until the convesation is over
            enabled = false;
            return;
        }

        if (!GameManager.instance.playerTurn)
        {
            return;
        }


        int moveHorizontal = 0;
        int moveVertical = 0;
        moveHorizontal = (int)(Input.GetAxisRaw("Horizontal"));
        moveVertical = (int)(Input.GetAxisRaw("Vertical"));

        //Prevent the player from moving diagonal
        if (moveHorizontal != 0)
            moveVertical = 0;


        //If the player moves on the x axis or on the y axis ( not both because both is the diagonal direction)
        if (moveHorizontal != 0 || moveVertical != 0)
        {
            //Move the player and pass in the generic NPC parameter because NPC can interact with player
            AttemptMove<NPCController>(moveHorizontal, moveVertical);
        }
	}

    public void PlayResult()
    {
        Application.LoadLevel("Result");
    }

    public void PlayerDeath()
    {
        playerAnimator.SetTrigger("playerDeath");
    }

    //Co-routine for moving units from one space to next, takes a parameter end to specify where to move to.
    private IEnumerator SmoothMovement(Vector3 end)
    {
        //Calculate the square remaining distance by calculating  difference between the current position and target end 
        //Use Vector3.sqrMagnitude ( x^2 + y^2 +z^2)
        float sqrRemainingDistance = (transform.position - end).sqrMagnitude;

        //Looping 
        while (sqrRemainingDistance > float.Epsilon)
        {
            //Set the new position to the point inverseMove*Time.deltaTime units closer to the end target
            //Move towards the rigidboy's position to the target end
            Vector3 newPosition = Vector3.MoveTowards(playerRigidbody.position, end, inverseMoveTime * Time.deltaTime);

            //Move the rigidbody position on the new position 
            playerRigidbody.MovePosition(newPosition);

            //Recalculate the remaning distance in order to check the condition to end the function
            sqrRemainingDistance = (transform.position - end).sqrMagnitude;

            //Return null for waiting a frame and loop until sqrRemainingDistance is close enough to zero to end the function
            yield return null;

        }

    }

    //Move returns true if it is able to move and false if not. 
    //Move takes parameters for x direction, y direction and a RaycastHit2D to check collision.
    //The out keywords causes argument to be parsed by argument in order to return more than one value
    bool Move(int xDir, int yDir, out RaycastHit2D hit)
    {
        Vector2 start = transform.position;//start is set to our current position
        Vector2 end = start + new Vector2(xDir, yDir);//end is set to the position passed by xDir and yDir

        //Disable  the boxcollider in order to prevent from hit our own collider when casting a line 
        playerCollider.enabled = false;

        //Cast a line from start point to end point, checking collision on blocking layer
        hit = Physics2D.Linecast(start, end, blockingLayer);

        //Enblae the box collider
        playerCollider.enabled = true;

        //Check if anything was hit
        if (hit.transform == null)
        {
            //If nothing was hit, start SmoothMovement co-routine passing in the Vector2 end as destination in order to start moving the object
            StartCoroutine(SmoothMovement(end));

            //Return true to say that Move was successful
            return true;
        }

        //If something was hit ,return false , move was uncessful
        return false;
    }

    //Attemp Move demonstrates the movements of the player , it takes a generic type T in order to behave with different types of object
    //Like soldier, trees, general, and pass in the x direction and y direction
    private void AttemptMove<T>(int xDir, int yDir)
        where T: Component
    {
        //Debug.Log("t");

        RaycastHit2D hit;//hit will store whatever our linecast hits when Move is called

        //Set canMove to true if is Move succesfull , false if is failed
        bool canMove = Move(xDir, yDir, out hit);

        //Check if the player was able to move
        if (Move(xDir, yDir, out hit))
        {
            //Call RandomizeSfx function of the static instance of SoundManager class and parse in two move sound seperated with comma
            //To choose and play randomly one of these two sounds
            SoundManager.instance.RandomizeSfx(moveSound1, moveSound2);
        }

        GameManager.instance.playerTurn = false;
        
        //Check if anything was hit by linecast
        if (hit.transform == null)
        {
            return;
        }

        

        //If something was hit , specify what the type of objects hited when our objects is moving
        //Get the component reference of type T attached to that objects
        T hitComponent = hit.transform.GetComponent<T>();

        //If canMove is false and hitComponent is not equal to null, meaning MovingObject is blocked and has hit something it can interact with.
        if (!canMove && hitComponent != null)
        {
            //Call a function OnCantMove to describe how the object cant move , the type T allow us using the generally type of component
            //It can be player hit walls or , enemy hit player , enemy hit walls, then we can implement the OnCantMove function 
            //in the class inherit from MovingObject
            OnCantMove(hitComponent);
        }
    }


    //The NPC can interact with the player
    private void OnCantMove<T>(T component)
    where T:Component
    {

        NPCController npc = component as NPCController;


        //Check if npc is still enabled , meaning the player hasn't begun the conversation from this npc
        if (npc.isActiveAndEnabled)
        {
            npc.StartConversation();
        }
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.tag == "Start") return;
        playerAnimator.SetTrigger("playerDissapear");
    }
   
}
