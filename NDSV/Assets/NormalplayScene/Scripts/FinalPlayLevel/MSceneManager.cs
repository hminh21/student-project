using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MSceneManager : MonoBehaviour {

    public static MSceneManager instance = null;

    void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        else if (instance != this)
        {
            Destroy(gameObject);
        }
    }

    public void SwitchScene(string sceneName)
    {
        Application.LoadLevel(sceneName);
    }

    public void PlayDoor2()
    {
        LevelManager.instance.indexDoor = 1;
        Application.LoadLevel("BlackScene");
    }
    public void PlayDoor3()
    {
        LevelManager.instance.indexDoor = 2;
        Application.LoadLevel("BlackScene");
    }
    public void PlayDoor4()
    {
        LevelManager.instance.indexDoor = 3;
        Application.LoadLevel("BlackScene");
    }

    public void PlayDoor1()
    {
        LevelManager.instance.indexDoor = 0;
        Application.LoadLevel("BlackScene");
    }

    public void PlayPlayingScene()
    {
        Application.LoadLevel("PlayingScene");
    }
}
