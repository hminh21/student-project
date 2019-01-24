using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class FinalManager : MonoBehaviour {

      public static FinalManager instance = null;

    [Header("Components")]
    public GameObject popUpMenu;
    public GameObject popUpHelp;
    public GameObject conversation;

    [Header("Text")]
    public Text scoreText;
    public Text levelText;

    [Header("Images")]
    public Image[] heart_Player;
    public Image[] heart_Dof;
    public Image levelImage;
    public Image damageImage;

    public int gameLife;//Base on game mode: Easy : 3 life , Normal:2 life , Hard :1

    public int score { get; set; }
    public int heartCount_Player;//{ get; set; }
    public int heartCount_Dof; //{ get; set; }
    public bool pauseGame { get; set; }

    [HideInInspector]
    public bool gameOver = false;

    private DoorController doorController;

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
    }

	// Use this for initialization
	void Start () 
    {

        score = LevelManager.instance.scoreInOneScene;
        scoreText.text = "Score:" + score;
        gameLife = LevelManager.instance.playerHealth;
        heartCount_Player = LevelManager.instance.heartCount_Player;
        heartCount_Dof = LevelManager.instance.heartCount_Dof;
        levelText.text = "Màn chơi cuối";

        ////Display the player's life
        //for (int i = heartCount_Player - 1; i < gameLife - 1; i++)
        //{
        //    heart_Player[i + 1].gameObject.SetActive(false);
        //}

        for (int i = 0; i < heartCount_Player; i++)
        {
            heart_Player[i].gameObject.SetActive(true);
        }
        for (int i = heartCount_Dof - 1; i < 2; i++)
        {
            heart_Dof[i + 1].gameObject.SetActive(false);
        }


        doorController = LevelManager.instance.doors[LevelManager.instance.indexDoor];
        //Debug.Log(LevelManager.indexDoor);
        //Debug.Log(doorController.QASetList[0].question);
        FinalMCManager.instance.BeginConversation(doorController);
	}
	
	// Update is called once per frame
	void Update () 
    {
	
	}

    public void PassFinal()
    {
         
         Application.LoadLevel("FinalSuccessResultScene");
            
         //Save the result to database
         DataBaseLoader.SaveGameInNormalScene(LevelManager.instance.playerID, LevelManager.instance.sceneID, LevelManager.instance.scoreInOneScene, true);
    }

    public void GameOver()  
    {
        Application.LoadLevel("FinalFailedResultScene");

        //Load the isCompleted scene add pass in the SaveGameInNormalScene function to save the isCompleted properties in case of plalyer play the scene again and does not pass it but has passed it before
        bool isCompleted = DataBaseLoader.LoadResultInOneScene(LevelManager.instance.playerID, LevelManager.instance.sceneID);
        bool m_result = false;

        if (isCompleted == true)
            m_result = true;
        //Save the result to database
        DataBaseLoader.SaveGameInNormalScene(LevelManager.instance.playerID, LevelManager.instance.sceneID, LevelManager.instance.scoreInOneScene, m_result);
    }

    public void IncreaseScore()
    {
        score++;
        scoreText.text = "Score:" + score.ToString();

    }

    public void DecreaseScore()
    {
        score--;
        scoreText.text = "Score:" + score.ToString();
    }

    public void LoseHeartPlayer()
    {

        heart_Player[heartCount_Player - 1].gameObject.SetActive(false);
        heartCount_Player--;

    }


    public void LoseHeartDof()
    {

        heart_Dof[heartCount_Dof - 1].gameObject.SetActive(false);
        heartCount_Dof--;

    }

    public void ResumeGame()
    {
        popUpMenu.SetActive(false);
        pauseGame = false;
    }
    public void GamePause()
    {

        popUpMenu.SetActive(true);
        pauseGame = true;
    }

    public void Instruction()
    {
        popUpHelp.SetActive(true);
    }

    public void CloseHelp()
    {
        popUpHelp.SetActive(false);
    }

    private void HideLevelIntro()
    {
        levelImage.gameObject.SetActive(false);
        levelText.gameObject.SetActive(false);
    }

    public void RestartLevel()
    {
        LevelManager.instance.wasRandom = false;
        LevelManager.instance.scoreInOneScene = 0;
        LevelManager.instance.heartCount_Player = gameLife;
        LevelManager.instance.heartCount_Dof = 3;

        Application.LoadLevel("OutDoor");
    }

    public void ExitToMain()
    {
        Application.LoadLevel("Menu");
    }
}
