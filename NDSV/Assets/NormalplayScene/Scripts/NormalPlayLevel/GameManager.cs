using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;

public class GameManager : MonoBehaviour {

    public static GameManager instance = null;

    //Components
    [Header("Components")]
    public GameObject general;
    public GameObject conversation;
    public GameObject startPosition;
    public GameObject endPosition;
    public GameObject timeHole;
    public GameObject playerInstantiate;
    public GameObject popUpMenu;
    public GameObject popUpHelp;
    public GameObject menuElements;
    public GameObject confirmMessage;

    //Text
    [Header("Text")]
    public Text scoreText;
    public Text levelText;

    //Image
    [Header("Images")]
    public Image[] hearts;
    public Image levelImage;
    public Image damageImage;
    
    //Int
    public int gameLife;//Base on game mode: Easy : 3 life , Normal:2 life , Hard :1
   
    //Float
    public float levelStartDelay = 2f;
    public float turnDelay = 0.1f;


   

    public int score { get; set; }
    public int heartCount { get; set; }
    public bool pauseGame { get; set; }

    
    public PlayerController player;

    [HideInInspector]
    public bool gameOver = false;

    [HideInInspector]
    public bool playerTurn = true;

    [HideInInspector]
    public bool playerStartConversation = false;

    [HideInInspector]
    public bool playerOutConversation = true;//The player is out the convesatoin

   
   
    

    //Data Source (static)
    int QACount;
    AnswerSet[] mainQuestionsSource = new AnswerSet[15];
    //{
    //   new AnswerSet("Lý Thường Kiệt là hậu duệ của vị vua nổi tiếng nào?",
    //                  "Ngô Quyền","Lê Hoàn","Lý Công Uẩn" ,"Cả ba đáp án đều sai",0),
    //   new AnswerSet("Trước khi trở thành quan thái úy của triều đình, Lý Thường Kiệt là?",
    //                  "Quan văn","Quan võ","Thái giám" ,"Chưa từng làm quan trước đó",2),
    //new AnswerSet("Tinh thần chủ động đối phó với quân Tống của nhà Lý thể hiện rõ trong chủ trương",
    //                  "Vườn không nhà trống","Ngồi yên đợi giặc không bằng đem quân đánh trước để chặn mũi nhọn của giặc","Lập phòng tuyến chắc chắn để chặn giặc" ,"Tích cực chuẩn bị lương thảo, vũ khí, luyện quân để chống lại thế mạnh của giặc",1),
    //new AnswerSet("Khi biết quân Tống sang xâm lược, Lý Thường Kiệt làm gì",
    //                  "Tấn công thành Ung Châu","Tấn công thành Liêm Châu","Dựng phòng tuyến Như Nguyệt" ,"Cả A và B",3)
    //};

    AnswerSet[] subQuestionsSource = new AnswerSet[10];
    //{
    //    new AnswerSet("Lý Thường Kiệt thọ bao nhiêu tuổi?",
    //                  "85","86","87" ,"88",1),
    //   new AnswerSet("Tác phẩm sau đây là của Lý Thường Kiệt?",
    //                  "Nam Quốc sơn hà","Chiếu Xuất Quân","Ðại Nam Quốc Sử Diễn Ca" ,"Phạt Tống lộ bố văn",3),
    //new AnswerSet("Lý Thường Kiệt hai lần làm Tể tướng dưới triều vua nào?",
    //                  "Lý Thánh Tông","Lý Nhân Tông","Lý Thần Tông" ,"Lý Thái Tông",1),
    //new AnswerSet("Tổn thất của quân Tống sau khi xâm lược nước ta?",
    //                  "76.600 quân và 8 vạn phu","82.200 quân và 8 vạn phu","86.600 quân và 9 vạn phu" ,"92.200 quân và 9 vạn phu",0),
    //new AnswerSet("Lực lượng quân Tống sang xâm lược nước ta gồm bao nhiêu quân?",
    //                  "100.000 quân chiến đấu, 200.000 dân phu","150.000 quân chiến đấu, 200.000 dân phu", "100.000 quân chiến đấu, 150.000 dân phu","150.000 quân chiến đấu, 150.000 dân phu",0)
                      
    //};

    private List<AnswerSet> randomMainQASet = new List<AnswerSet>();
    private List<AnswerSet> randomSubQASet = new List<AnswerSet>();
    private GameObject[] soldiers;
    private bool enemiesMoving;
    private NPCController npc;
    private bool doingSetup;

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
            //Then destroy this. This enforces our singleton pattern, meaning there can only ever be one instance of a GameManager.
            Destroy(gameObject);
        }

        //DontDestroyOnLoad(gameObject);

    }

	// Use this for initialization
	private void Start () 
    {
        
        NotDestroyMusic.Instance.gameObject.SetActive(false);

        //Load the QA Set from database sql server to mainQASetSrc and sub QA SetSrc pass in the scene ID 
        DataBaseLoader.LoadQADatabase(LevelManager.instance.sceneID, mainQuestionsSource, subQuestionsSource);

        //Random the data to NPC in one scene
        InitData();

        heartCount = LevelManager.instance.playerHealth;
        score = 0;

        levelText.text = "Màn chơi Lý Thường Kiệt";

        doingSetup = true;
        //Invoke("HideLevelIntro", levelStartDelay);

        //Spawn the player and time hole for level intro
        StartCoroutine(SpawnObject());

        //Display the player's life
        for (int i = 0 ; i < heartCount; i++)
        {
            hearts[i].gameObject.SetActive(true);
        }

        //Debug.Log("Câu hỏi chính" + mainQuestionsSource[0]);
        //Debug.Log("Câu hỏi phụ" + subQuestionsSource[0]);


	}
	

    public void GameOver()
    {
        //Disable this Game Manager
        enabled = false;

        player.PlayerDeath();

        //Disable the player movement
        player.enabled = false;

        //if it's soldier or all the question is true, then player is out the convesation
        conversation.gameObject.SetActive(false);

        LevelManager.instance.result = false;

        LevelManager.instance.scoreInOneScene = score;

    }


   


    public void IncreaseScore()
    {
        score++;
        scoreText.text = "Score:" + score.ToString();
 
    }

    public void LoseHeart()
    {

        hearts[heartCount - 1].gameObject.SetActive(false);
        heartCount--;
        
    }

   


	// Update is called once per frame
	private void Update () 
    {
        if (playerTurn  || enemiesMoving)
        {
            return;
        }
           

        StartCoroutine(MovePlayer());
	}

    public void ResumeGame()
    {
        popUpMenu.SetActive(false);
        player.enabled = true;
        pauseGame = false;
    }
    public void GamePause()
    {
       
        popUpMenu.SetActive(true);
        pauseGame = true;
    }

    public void Instruction()
    {
        popUpHelp.SetActive(true);
    }

    public void CloseHelp()
    {
        popUpHelp.SetActive(false);
    }


    private void InitData()
    {


        //Load random QAs from mainQuestionSouce to general
        LoadRandomQAToGeneral();

        //Load random QAs from subQuestionSource to random soldier
        LoadRandomQAToSoldiers();
    }

    private void LoadRandomQAToSoldiers()
    {
        Debug.Log("Run GameManager");
        const int maxSubQuestionCount = 7;

        //Random the count of sub question in one scene
        int subQuestionCount = Random.Range(1, 5);
        Debug.Log("Sub question:" +  subQuestionCount);
        int length = 0;
        int randomIndex;
        int[] randomArray = new int[subQuestionCount];

        //Get subQuestionCount random different QA set from the subQuestionSource
        for (int i = 0; i < subQuestionCount;i++)
        {
            //While the random index is exists in the random index array
            do
            {
                //Keep randomizing the index
                randomIndex = Random.Range(0, maxSubQuestionCount);
            } while (IsExists(randomArray, randomIndex));

            //Add the new randomIndex to the random index array
            randomArray[length++] = randomIndex;

            //Add the QASetSource to the randomSubQASet list
            randomSubQASet.Add(subQuestionsSource[randomIndex]);
        }

       //Find all the soldies GameObject
        soldiers = GameObject.FindGameObjectsWithTag("Soldier");

        //Check if the soldier count is smaller than  number of sub QA Set
        if (soldiers.Length < randomSubQASet.Count) return;//Then we don't have enough soldies to be added by QA 

        int[] tempArray = new int[subQuestionCount];
        length = 0;

        //Add all the SubQASet to the random soldier in soldiers list
        foreach (var set in randomSubQASet)
        {
             //While the random index is exists in the random index array
            do
            {
                //Keep randomizing the index
                randomIndex = Random.Range(0, soldiers.Length);
            } while (IsExists(tempArray, randomIndex));

            //Add the new randomIndex to the random index array
            tempArray[length++] = randomIndex;

            // Add the NPCController's Script component to the soldier GameObject
            npc = soldiers[randomIndex].AddComponent<NPCController>();

            //Change the settings of this component by using the AddQA function
            npc.AddQA(set);

        }
    }

    private void LoadRandomQAToGeneral()
    {
        const int mainQuestionCount = 13;
        int[] randomArray = new int[mainQuestionCount];
        int length = 0;
        int randomIndex;
        //Get SIX (static) random different QA set from the mainQuestionSource
        for (int i = 0; i < 6; i++)
        {
            //While the random index is exists in the random index array
            do
            {
                //Keep random the index 
                randomIndex = Random.Range(0,mainQuestionCount);
            } while (IsExists(randomArray, randomIndex));


            //Add the new randomIndex to the random index array
            randomArray[length++] = randomIndex;

            //Add the QASetSource to the randomMainQASet list
            randomMainQASet.Add(mainQuestionsSource[randomIndex]);
        }

        // Add the NPCController's Script component to the general GameObject
        npc = general.AddComponent<NPCController>();

        //Change the settings of this component by using the AddQA function
        npc.AddQA(randomMainQASet);
    }

    private bool IsExists(int[] randomArray,int x)
    {
        for (int i = 0 ; i < randomArray.Length ; i++)
        {
            if (x == randomArray[i]) return true;
        }
        return false;
    }

    IEnumerator MovePlayer()
    {

        enemiesMoving = true;

        yield return new WaitForSeconds(turnDelay);

        yield return new WaitForSeconds(turnDelay);

        playerTurn = true;
        enemiesMoving = false;
    }

    private void HideLevelIntro()
    {
        levelImage.gameObject.SetActive(false);
        levelText.gameObject.SetActive(false);

        doingSetup = false;

    }

    IEnumerator SpawnObject()
    {
        //Wait while data is initialize
        yield return new WaitForSeconds(1f);

        //Spawn the time hole
        Instantiate(timeHole, startPosition.transform.position, Quaternion.identity);

        yield return new WaitForSeconds(1f);

        Instantiate(playerInstantiate, startPosition.transform.position, Quaternion.identity);

        GameObject playerGameObject = GameObject.FindGameObjectWithTag("User");
        player = playerGameObject.GetComponent<PlayerController>();

    }

    public void SpawnTimeHole()
    {
        //Spawn the time hole at the end position
        Instantiate(timeHole, endPosition.transform.position, Quaternion.identity);
    }


    public void RestartLevel()
    {
        Application.LoadLevel(Application.loadedLevel);
    }

    public void ShowMessage()
    {
        menuElements.SetActive(false);
        confirmMessage.SetActive(true);
    }

    public void Close()
    {
        menuElements.SetActive(true);
        confirmMessage.SetActive(false);
    }

    

    public void ExitToMain()
    {
        Application.LoadLevel("Menu");
    }

}
