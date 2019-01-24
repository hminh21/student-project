using UnityEngine;
using System.Collections;
using UnityEngine.UI;
public class FinalResultManagerScene : MonoBehaviour 
{
    [Header("Animator")]
    public Animator animHBT;
    public Animator animLTK;
    public Animator animTHD;
    public Animator animHCM;
    public Animator animQT;
    public Animator animTotal;
    public Animator animButton;

    [Header("Sounds")]
    public AudioClip showScore;
    public AudioClip soundScene;
	// Use this for initialization
	void Start () 
    {
        SoundManager.instance.PlaySingleClip(showScore);
        StartCoroutine(PlayHBT());
	}
	
	// Update is called once per frame
	void Update () 
    {

	}

    IEnumerator PlayHBT()
    {
        yield return new WaitForSeconds(showScore.length);
        animHBT.SetTrigger("HCMisPlayed");
        SoundManager.instance.PlaySingleClip(showScore);

        StartCoroutine(PlayLTK()); //Play next score
    }

    IEnumerator PlayLTK()
    {
        yield return new WaitForSeconds(showScore.length);
        animLTK.SetTrigger("HBTisPlayed");
        SoundManager.instance.PlaySingleClip(showScore);

        StartCoroutine(PlayTHD());
    }

    IEnumerator PlayTHD()
    {
        yield return new WaitForSeconds(showScore.length);
        animTHD.SetTrigger("LTKisPlayed");
        SoundManager.instance.PlaySingleClip(showScore);

        StartCoroutine(PlayQT());
    }

    IEnumerator PlayQT()
    {
        yield return new WaitForSeconds(showScore.length);
        animQT.SetTrigger("THDisPlayed");
        SoundManager.instance.PlaySingleClip(showScore);

        StartCoroutine(PlayTotalScore());
    }

    IEnumerator PlayTotalScore()
    {
        yield return new WaitForSeconds(showScore.length);
        animTotal.SetTrigger("QTisPlayed");
        SoundManager.instance.PlaySingleClip(showScore);

        StartCoroutine(PlayButton());
    }

    IEnumerator PlayButton()
    {
        yield return new WaitForSeconds(showScore.length);
        SoundManager.instance.PlaySingleClip(soundScene);
        animButton.SetTrigger("TotalisPlayed");
    }

    public void LoadOutroScene()
    {
        Application.LoadLevel("Outro");
    }

    public void LoadChoosingScene()
    {
        Application.LoadLevel("ChoosingScene");
    }
}
