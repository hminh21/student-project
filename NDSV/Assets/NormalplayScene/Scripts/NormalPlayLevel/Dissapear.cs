using UnityEngine;
using System.Collections;

public class Dissapear : MonoBehaviour {

    private BoxCollider2D boxCollider2D;
    // Use this for initialization
    void Start()
    {
        boxCollider2D = GetComponent<BoxCollider2D>();


    }

    //Check if the player move in the time hole
    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.tag != "User") return;

        // Start the coroutine TimeHoleDissapear 
        StartCoroutine(TimeHoleDissapear());
    }

    private IEnumerator TimeHoleDissapear()
    {
        //Wait until the player disspear animation finishes

        yield return new WaitForSeconds(1f);

        //Find the time hole gameobject and get the animator component
        GameObject timeHole = GameObject.FindGameObjectWithTag("TimeHole");
        Animator timeHoleAnimator = timeHole.GetComponent<Animator>();
        if (timeHoleAnimator == null) yield return null;

        //Play the disspear animation
        timeHoleAnimator.SetTrigger("playerInHole");

        //Destroy the time Hole gameObject
        Destroy(timeHole, 1f);

        boxCollider2D.enabled = false;

        //Then move to the result scene
        yield return new WaitForSeconds(1f);
        Application.LoadLevel("Result");
    }
}
