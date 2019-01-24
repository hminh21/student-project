using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;
public class MLevelManager : MonoBehaviour {


    

	public void SwitchScenes(string sceneName)
    {
        Application.LoadLevel(sceneName);
    }

    private void Start()
    {
        //Load the game mode from sql and assign it to playerHealth
        LevelManager.instance.playerHealth = DataBaseLoader.LoadGameMode(LevelManager.instance.playerID);

    }

    public void PlaySceneWithLevel(int gameLife)
    {
        //Call the function CreateNewGame from the DatabaseLoader
        DataBaseLoader.CreateNewGame(LevelManager.instance.playerID);

        //Save game mode to sql
        DataBaseLoader.SaveGameModeToDb(LevelManager.instance.playerID, gameLife);

        LevelManager.instance.playerHealth = gameLife;

        Application.LoadLevel("ChoosingScene");


    }

    public void ContinueGame()
    {
        //Check if playerHealth != 0 , meaning user has created new game
        if (LevelManager.instance.playerHealth != 0)
        {
            Application.LoadLevel("ChoosingScene");

        }
    }

    public void ExitGame()
    {
        Application.Quit();
    }
}
