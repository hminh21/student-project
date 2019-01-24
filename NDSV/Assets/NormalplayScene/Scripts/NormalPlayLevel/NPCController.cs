using UnityEngine;
using System.Collections;
using System.Collections.Generic;


public class NPCController : MonoBehaviour {

    private string[] levelName = new string[]
    {
        "Hai Bà Trưng",
         "Trần Hưng Đạo",
         "Quang Trung",
        "Lý Thường Kiệt",
       
        
    };
    


    public int QASetCount { get; set; }
    [HideInInspector]
    public List<AnswerSet> QASetList = new List<AnswerSet>();
    public string dummyText { get; set; }

    //[HideInInspector]
    public AnswerSet answerSet = new AnswerSet();


    public void AddQA(AnswerSet set)
    {
        answerSet.question = set.question;
        answerSet.answerA = set.answerA;
        answerSet.answerB = set.answerB;
        answerSet.answerC = set.answerC;
        answerSet.answerD = set.answerD;
        answerSet.trueAnswer = set.trueAnswer;
        QASetCount = 1;
    }

    public void AddQA(List<AnswerSet> list)
    {
        foreach(var set in list)
        {
            QASetList.Add(set);
        }

        QASetCount = list.Count;

    }
	// Use this for initialization
	void Start () 
    {
        dummyText = "Bạn đang ở dòng thời gian " + levelName[LevelManager.instance.sceneID]+ ", muốn thoát ra khỏi đây phải trả lời đúng hết những câu hỏi sau:\n(Ấn Space để tiếp tục)";
	}


    //Playing the conversation
    public void StartConversation()
    {
        //Debug.Log(GameManager.instance.playerStartConversation);
        //Check if player started the conversation and out this conversation of this npc 
       
      

        //Player is in the conversation
        GameManager.instance.conversation.SetActive(true);
        GameManager.instance.playerStartConversation = true;

        //Get the Multiple-Choice Manager Script
        MCManager conversation = GameObject.FindGameObjectWithTag("Conversation").GetComponent<MCManager>() as MCManager;
        if (conversation == null)
        {
            Debug.Log("conversation not found");
            return;
        }
            

        //The Multiple-Choice will begin the conversation with this npc and player
        conversation.BeginConversation(this);

        enabled = false;
    }
}
