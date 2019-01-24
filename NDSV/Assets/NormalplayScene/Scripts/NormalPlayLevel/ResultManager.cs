using UnityEngine;
using System.Collections;

public class ResultManager : MonoBehaviour 
{

    public GameObject[] tickIcon;
    public Animator finalLevelAnimator;
    public GameObject lockIcon;
    public GameObject lockScreen;
    public AudioClip unlockSound;



    public bool isUnlock { get; set; }
    private bool[] isCompleted = new bool[5];
    private int countCompletedLevel = 0;



    private void Start()
    {
        isUnlock = false;

        Debug.Log("PlayerID " + LevelManager.instance.playerID);

        //Load the isCompleted variable in each scene in to the isCompleted array
        DataBaseLoader.LoadResultDataBase(LevelManager.instance.playerID, isCompleted);

        //Check if the scene is completed
        for (int i = 0; i < isCompleted.Length;i++ )
        {
            if (isCompleted[i])
            {
                //Enable the tick icon
                tickIcon[i].SetActive(true);
                countCompletedLevel++;
            }
        }

       

        if (countCompletedLevel == 4)// 4 level is completed  , the final level is unlock
        {
            
            StartCoroutine(UnlockFinalScene());     
        }
        else if (countCompletedLevel == 5)
        {
            lockIcon.SetActive(false);
            lockScreen.SetActive(false);
            isUnlock = true;
        }

    }

    IEnumerator UnlockFinalScene()
    {
        
        
            SoundManager.instance.PlaySingleClip(unlockSound);
            finalLevelAnimator.SetTrigger("isUnlock");
            yield return new WaitForSeconds(5);
            isUnlock = true;
            LevelManager.instance.firstUnlock = false ;
            lockIcon.SetActive(false);
            lockScreen.SetActive(false);
        

        
        
        
    }


}
