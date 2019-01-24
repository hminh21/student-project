using UnityEngine;
using System.Collections;
using UnityEngine.UI;
public class FinalResultManager : MonoBehaviour {

    private int[] scoreScene = new int[6];

    [Header("Text")]
    public Text[] scoreText = new Text[6];

	// Use this for initialization
	void Start () 
    {
        DataBaseLoader.LoadScoreAllScenes(LevelManager.instance.playerID, ref scoreScene); //load score

        for (int i = 0; i < scoreText.Length; i++)
        {
            scoreText[i].text = scoreScene[i].ToString();
        }
	}

	// Update is called once per frame
	void Update ()
    {
	}


}
