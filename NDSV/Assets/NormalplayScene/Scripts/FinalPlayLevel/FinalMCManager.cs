using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class FinalMCManager : MonoBehaviour 
{
    public static FinalMCManager instance = null;
    public Text introText;
    public GameObject answerPanel;
    public Color flashColor = new Color(1f, 0f, 0f, 0.1f);
    public float flashSpeed = 5f;

    [Header("Sounds")]
    public AudioClip showTextSound;
    public AudioClip trueSound;
    public AudioClip falseSound;

    [Header("QA Set Text")]
    public Text questionText;
    public Text ansAText;
    public Text ansBText;
    public Text ansCText;
    public Text ansDText;

    [Header("Select Icon")]
    public Image selectAIcon;
    public Image selectBIcon;
    public Image selectCIcon;
    public Image selectDIcon;
    public Image damageImage;

    private int currentSelection = 0;
    private int[,] answerBoard = new int[,] { { 0, 1 }, { 2, 3 } };
    private int icol = 0;
    private int irow = 0;
    private int trueAnswer = 0;
    private int questionIndex = 0;
    private DoorController npcCharacter;
    private bool skipIntro = false;
    private bool skipOutro = false;

    //If player is dead => true
    private bool isDead = false;

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
            //Then destroy this. This enforces our singleton pattern, meaning there can only ever be one instance of a FinalManager.
            Destroy(gameObject);
        }

        //DontDestroyOnLoad(gameObject);

    }

	// Use this for initialization
	void Start () 
    {
        damageImage.color = Color.clear;
	}
	
	// Update is called once per frame
	void Update () 
    {
        if (!isDead) //If player is alive, still get key down and load QA Set
        {
            if (Input.GetKeyDown(KeyCode.Space))
            {
                skipIntro = true;
                introText.gameObject.SetActive(false);
            }

            //Load QA Set to the conversation panel if intro is skipped or npc is soldier
            if (skipIntro)
            {

                if (!skipOutro)
                {

                    answerPanel.SetActive(true);
                    questionText.gameObject.SetActive(true);

                    int selectedAnswer = Selection();

                    if (selectedAnswer != -1)
                    {
                        StartCoroutine(CheckMultipleChoice(selectedAnswer));
                    }
                }
            }
        }
	}

    //This fucntion will manage the conversation between the player and npc , including:
    //Load Intro text( if npc is general)
    //Load QA Set to the conversation panel
    public void BeginConversation(DoorController npc)
    {
        SoundManager.instance.PlaySingleClip(showTextSound);

        //Debug.Log(npc.QASetList.Count);
        npcCharacter = npc;
        introText.gameObject.SetActive(true);
        introText.text = npcCharacter.dummyText;
        LoadQASet(npcCharacter);

    }

    private void LoadQASet(DoorController npc)
    {
            //If not , meaning the npc conversating with the player is general
            //Then we load the first QA Set from the QASetList
        //Debug.Log(npc.QASetList[0].question);
        questionText.text = (questionIndex + 1).ToString() + "." + npc.QASetList[questionIndex].question;
        ansAText.text = "A." + npc.QASetList[questionIndex].answerA;
        ansBText.text = "B." + npc.QASetList[questionIndex].answerB;
        ansCText.text = "C." + npc.QASetList[questionIndex].answerC;
        ansDText.text = "D." + npc.QASetList[questionIndex].answerD;
        trueAnswer = npc.QASetList[questionIndex].trueAnswer;

        //Reset the current row and column to 0
        irow = 0;
        icol = 0;

    }

    private int Selection()
    {


        if (Input.GetKeyDown(KeyCode.LeftArrow))
        {
            PlayShowText(icol);
            icol -= 1;
        }
        else if (Input.GetKeyDown(KeyCode.RightArrow))
        {
            PlayShowText(icol);
            icol += 1;
        }
        else if (Input.GetKeyDown(KeyCode.UpArrow))
        {
            PlayShowText(irow);
            irow -= 1;
        }
        else if (Input.GetKeyDown(KeyCode.DownArrow))
        {
            PlayShowText(irow);
            irow += 1;
        }
        else if (Input.GetKeyDown(KeyCode.Return)) return answerBoard[irow, icol];

        //Clamp the current column or row
        irow = Mathf.Clamp(irow, 0, 1);
        icol = Mathf.Clamp(icol, 0, 1);

        currentSelection = answerBoard[irow, icol];
        //Debug.Log(currentSelection);

        //Hide all the selected icon
        HideAllSelectIcon();

        //Load the select icon on the selected text, base on the current selection
        LoadSelectIcon(currentSelection);

        //If none of this key is putting down , then return -1
        return -1;
    }

    private void LoadSelectIcon(int index)
    {
        switch (index)
        {
            case 0:
                selectAIcon.gameObject.SetActive(true);
                break;
            case 1:
                selectBIcon.gameObject.SetActive(true);
                break;
            case 2:
                selectCIcon.gameObject.SetActive(true);
                break;
            case 3:
                selectDIcon.gameObject.SetActive(true);
                break;
        }

    }

    private void HideAllSelectIcon()
    {
        selectAIcon.gameObject.SetActive(false);
        selectBIcon.gameObject.SetActive(false);
        selectCIcon.gameObject.SetActive(false);
        selectDIcon.gameObject.SetActive(false);

    }

    private IEnumerator CheckMultipleChoice(int selection)
    {

        //Check if the player choose the correct answer
        if (selection == trueAnswer)
        {
            SoundManager.instance.PlaySingleClip(trueSound);

            //Increase score
            FinalManager.instance.IncreaseScore();

                if (questionIndex == (npcCharacter.QASetCount - 1))
                {
                    //Lose heart of Dof
                    FinalManager.instance.LoseHeartDof();

                    if (FinalManager.instance.heartCount_Dof > 0)
                    {
                        questionText.text = "Ngươi giỏi lắm.";
                    }
                    else
                    {
                        questionText.text = "Hahahahahaha ta vẫn chưa tin được là ngày hôm nay vẫn có người am hiểu lịch sử Việt Nam đến như vậy, ta cứ tưởng truyền thống đó đã bị mai một bởi cái thế hệ chỉ biết dựa dẫm vào công nghệ thôi chứ.";
                    }

                    skipOutro = true;

                    //Disable this door
                    LevelManager.instance.doors[LevelManager.instance.indexDoor].isCompleted = true;

                    if (FinalManager.instance.heartCount_Dof > 0)
                        yield return new WaitForSeconds(2f);
                    else
                        yield return new WaitForSeconds(5f);

                    //Player out the conversation
                    PlayerOutConversation();

                    yield return null;

                }
                else
                {
                    //Go to the next question
                    questionIndex++;
                    LoadQASet(npcCharacter);
                }
        }
        else//Player chosse the false answer
        {
            SoundManager.instance.PlaySingleClip(falseSound);

                //Decrease the score
            if (FinalManager.instance.score > 0)
                FinalManager.instance.DecreaseScore();

                //Lose heart of player
                FinalManager.instance.LoseHeartPlayer();
                damageImage.color = flashColor;


                if (FinalManager.instance.heartCount_Player == 0)
                {
                    isDead = true;
                    answerPanel.SetActive(false);
                    questionText.text = "Hahahaha ngươi thua rồi, hãy trả giá bằng mạng sống của mình đi.";
                    yield return new WaitForSeconds(4);
                    questionText.gameObject.SetActive(false);
                    FinalManager.instance.GameOver();
                    //yield return null;
                }

                //Load current question
                LoadQASet(npcCharacter);

                yield return new WaitForSeconds(0.1f);
                damageImage.color = Color.clear;
        }
    }

    private void PlayerOutConversation()
    {

        //if it's soldier or all the question is true, then player is out the convesation
        FinalManager.instance.conversation.gameObject.SetActive(false);

        answerPanel.SetActive(false);
        questionText.gameObject.SetActive(false);

        skipOutro = false;

        LevelManager.instance.heartCount_Player = FinalManager.instance.heartCount_Player;
        LevelManager.instance.heartCount_Dof = FinalManager.instance.heartCount_Dof;
        LevelManager.instance.scoreInOneScene = FinalManager.instance.score;

        if (LevelManager.instance.heartCount_Dof > 0)
        {
            Application.LoadLevel("OutDoor");
        }
        else
        {
            FinalManager.instance.PassFinal();
        }
    }



    private void PlayShowText(int currentSelection)
    {
        if (currentSelection == 0 || currentSelection == 1)
        {
            SoundManager.instance.PlaySingleClip(showTextSound);
        }
    }
}
