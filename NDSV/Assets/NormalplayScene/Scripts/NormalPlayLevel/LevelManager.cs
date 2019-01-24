using UnityEngine;
using System.Collections;

public class LevelManager : MonoBehaviour {

    public static LevelManager instance = null;

    //Normal play scene
    public int sceneID { get; set; }
    public int playerID { get; set; }
    public bool result { get; set; }
    public int scoreInOneScene { get; set; }
    public int totalScore { get; set; }
    public int playerHealth; //{ get; set; }


    //Final scene
    public DoorController[] doors = new DoorController[4]
    {
        new DoorController(),
        new DoorController(),
        new DoorController(),
        new DoorController()
    };
    public AudioClip doorSound { get; set; }
    public int indexDoor { get; set; }
    public int heartCount_Player ;//{ get; set; }
    public int heartCount_Dof;//{ get; set; }
    public bool wasRandom = false;

    //Choosing scene
    [HideInInspector]
    public bool firstUnlock = true;

    private void Awake()
    {
        //Check if instance already exists
        if (instance == null)
        {
            // If no set instance to this
            instance = this;
        }
        //If instance already exists and it's not this
        else if (instance != this)
        {
            //Then destroy this. This enforces our singleton pattern, meaning there can only ever be one instance of a GameManager.
            Destroy(gameObject);
        }
        DontDestroyOnLoad(gameObject);

    }


    IEnumerator Load()
    {
        yield return new WaitForSeconds(2);
    }

   

  


}
