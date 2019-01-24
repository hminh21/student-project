using UnityEngine;
using System.Collections;

public class SceneManager : MonoBehaviour {

    public AudioClip buttonClickSound;
    public void ExitToMenuScene()
    {
        SoundManager.instance.PlaySingleClip(buttonClickSound);
        Application.LoadLevel("Menu");
    }

    public void PlayHaiBaTrung()
    {
        SoundManager.instance.PlaySingleClip(buttonClickSound);
        //StartCoroutine(Load());
        Application.LoadLevel("HaiBaTrung");
        LevelManager.instance.sceneID = 0;
    }

    public void PlayTranHungDao()
    {
        SoundManager.instance.PlaySingleClip(buttonClickSound);
        Application.LoadLevel("TranHungDao");
        LevelManager.instance.sceneID = 1;
    }

    public void PlayQuangTrung()
    {
        SoundManager.instance.PlaySingleClip(buttonClickSound);
        Application.LoadLevel("QuangTrung");
        LevelManager.instance.sceneID = 2;
    }

    public void PlayLyThuongKiet()
    {
        SoundManager.instance.PlaySingleClip(buttonClickSound);
        Application.LoadLevel("LyThuongKiet");
        LevelManager.instance.sceneID = 3;
    }

    public void PlayFinalScene()
    {
        //Debug.Log("PlayFinalScene");
        ResultManager resultManager = GameObject.Find("ResultManager").GetComponent<ResultManager>();
        if (resultManager == null) return;
        if (resultManager.isUnlock)
        {
            Application.LoadLevel("FinalIntro");
            SoundManager.instance.PlaySingleClip(buttonClickSound);

            //Deactive the background music in scene menu
            NotDestroyMusic.Instance.gameObject.SetActive(false);

            LevelManager.instance.wasRandom = false;
        }
        LevelManager.instance.sceneID = 4;
        
    }
}
