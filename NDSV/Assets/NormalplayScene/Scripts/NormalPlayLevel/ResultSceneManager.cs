using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class ResultSceneManager : MonoBehaviour {


    public Text titleText;
    public Text scoreText;
    public Text resultText;
    public Image achievementImage;
    public AudioClip buttonClickSound;
    public AudioClip loseSound;
    public AudioClip winSound;

    private Sprite[] achievementSpriteSource;
    private Sprite missingAchievementSprite;

	// Use this for initialization
	void Start () 
    {

        achievementSpriteSource = Resources.LoadAll<Sprite>("Achievement");
        missingAchievementSprite = Resources.Load<Sprite>("MissingAchievement/question_icon");

        titleText.text = "Kết quả màn chơi";

        if (LevelManager.instance.result == true)
        {
            SoundManager.instance.PlaySingleClip(winSound);
            resultText.text = "Xin chúc mừng , bạn đã hoàn thành màn chơi";
            achievementImage.sprite = achievementSpriteSource[LevelManager.instance.sceneID];
            scoreText.text = "Số điểm đạt được:" + LevelManager.instance.scoreInOneScene;
        }
        else
        {
            SoundManager.instance.PlaySingleClip(loseSound);
            resultText.text = "Rất tiếc, bạn chưa hoàn thành màn chơi";
            achievementImage.sprite = missingAchievementSprite;
            scoreText.text = "Số điểm đạt được:" + LevelManager.instance.scoreInOneScene;
        }
	}
	
	public void PlayChoosingScene()
    {


        bool m_result;
        SoundManager.instance.PlaySingleClip(buttonClickSound);

        //Load the isCompleted scene add pass in the SaveGameInNormalScene function to save the isCompleted properties in case of plalyer play the scene again and does not pass it but has passed it before
        bool isCompleted = DataBaseLoader.LoadResultInOneScene(LevelManager.instance.playerID, LevelManager.instance.sceneID);

        //The player has completed the scene but when not complete the scene when play again
        if (isCompleted == true && LevelManager.instance.result == false)
        {
            //Save Game in normal scene
            DataBaseLoader.SaveGameInNormalScene(
                LevelManager.instance.playerID,
                LevelManager.instance.sceneID,
                LevelManager.instance.scoreInOneScene,
                isCompleted
                );
        }
        else
        {
            //Save Game in normal scene
            DataBaseLoader.SaveGameInNormalScene(
                LevelManager.instance.playerID,
                LevelManager.instance.sceneID,
                LevelManager.instance.scoreInOneScene,
                LevelManager.instance.result
                );
        }

        

        Application.LoadLevel("ChoosingScene");
    }
}
