using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class MCManager : MonoBehaviour {

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
    private bool isGeneral;
    private NPCController npcCharacter;
    private bool skipIntro = false;
    private bool skipOutro = false;

	// Use this for initialization
	void Start () 
    {
        damageImage.color = Color.clear;
	}
	
	// Update is called once per frame
	void Update () 
    {

        

        
      if (Input.GetKeyDown(KeyCode.Space))
      {
          skipIntro = true;
          introText.gameObject.SetActive(false);
      }

      
      
      //Load QA Set to the conversation panel if intro is skipped or npc is soldier
      if (skipIntro || npcCharacter.QASetCount == 1)
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
    //This fucntion will manage the conversation between the player and npc , including:
    //Load Intro text( if npc is general)
    //Load QA Set to the conversation panel
    public void BeginConversation(NPCController npc)
    {
        SoundManager.instance.PlaySingleClip(showTextSound);


        npcCharacter = npc;
        //Load Introtext(if npc is general)
        if (npcCharacter.QASetCount > 1)
        {
            introText.gameObject.SetActive(true);
            introText.text = npcCharacter.dummyText;
        }

        LoadQASet(npcCharacter);
      
    }

    private void LoadQASet(NPCController npc)
    {


        //If the count of the QASet is 1 ,meaning the npc conversating with the player is soldier
        if (npc.QASetCount == 1)
        {
            //Then we load QA Set from the answerSet
            //Load the QA set from the NPC
            questionText.text =  npc.answerSet.question;
            ansAText.text = "A." + npc.answerSet.answerA;
            ansBText.text = "B." + npc.answerSet.answerB;
            ansCText.text = "C." + npc.answerSet.answerC;
            ansDText.text = "D." + npc.answerSet.answerD;
            trueAnswer = npc.answerSet.trueAnswer;
            isGeneral = false;
        }
        else if (npc.QASetCount > 1)
        {
            //If not , meaning the npc conversating with the player is general
            //Then we load the first QA Set from the QASetList
            questionText.text =(questionIndex+1).ToString()+ "." + npc.QASetList[questionIndex].question;
            ansAText.text = "A." + npc.QASetList[questionIndex].answerA;
            ansBText.text = "B." + npc.QASetList[questionIndex].answerB;
            ansCText.text = "C." + npc.QASetList[questionIndex].answerC;
            ansDText.text = "D." + npc.QASetList[questionIndex].answerD;
            trueAnswer = npc.QASetList[questionIndex].trueAnswer;
            isGeneral = true;
        }

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

        currentSelection = answerBoard[irow,icol];
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
        //Debug.Log("Checking answer " + selection.ToString());
        //Check if the player choose the correct answer
        if (selection == trueAnswer)
        {
            SoundManager.instance.PlaySingleClip(trueSound);

            //Increase score
            GameManager.instance.IncreaseScore();

            if (isGeneral)//If this npc is general
            {
                if (questionIndex == (npcCharacter.QASetCount -1))//The player has finished the level
                {
                    questionText.text = "Xin chúc mừng bạn đã chơi hết , bạn có thể tiếp tục tìm các lính giấu các câu trả lời phụ hoặc ra hố đen thời gian để thoát";
                    answerPanel.gameObject.SetActive(false);
                    skipOutro = true;
                    LevelManager.instance.result = true;
                    //Debug.Log("Score in one scene" + GameManager.instance.score);
                    LevelManager.instance.scoreInOneScene = GameManager.instance.score;
                    GameManager.instance.endPosition.gameObject.SetActive(true);

                    yield return new WaitForSeconds(2f);

                    //Player out the conversation
                    PlayerOutConversation();

                    //Spawn the time hole at the End Game position
                    GameManager.instance.SpawnTimeHole();
                    
                    yield return null;
                   
                }
                else
                {
                    //Go to the next question
                    questionIndex++;
                    LoadQASet(npcCharacter);
                }
                
                
            }
            else
            {
                //If this npc is soldier
                //Player out the conversation
                PlayerOutConversation();
            }
        }
        else//Player chosse the false answer
        {
            SoundManager.instance.PlaySingleClip(falseSound);


            if (isGeneral)//If this npc is general
            {
                //Lose heart
                GameManager.instance.LoseHeart();
                damageImage.color = flashColor;


                if (GameManager.instance.heartCount == 0)
                {
                    GameManager.instance.GameOver();
                    yield return null;
                }

                //Load current question
                LoadQASet(npcCharacter);

                yield return new WaitForSeconds(0.1f);
                damageImage.color = Color.clear;
            }
            else
            {

                //If this npc is soldier
                //Player out the conversation
               PlayerOutConversation();
            }
        }
    }

   private void PlayerOutConversation()
    {
       
        //if it's soldier or all the question is true, then player is out the convesation
        GameManager.instance.conversation.gameObject.SetActive(false);
        GameManager.instance.playerStartConversation = false;

        //Enable the player script . the player now can move again
        GameManager.instance.player.enabled = true;

        answerPanel.SetActive(false);
        questionText.gameObject.SetActive(false);

        skipOutro = false;

        
    }

   

  private void PlayShowText(int currentSelection)
   {
      if (currentSelection == 0 || currentSelection == 1)
      {
          SoundManager.instance.PlaySingleClip(showTextSound);
      }
   }
}
