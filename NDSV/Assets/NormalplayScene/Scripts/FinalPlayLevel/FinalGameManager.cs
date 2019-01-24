using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;

public class FinalGameManager : MonoBehaviour {

    public static FinalGameManager instance = null;

    [Header("Components")]
    public GameObject popUpMenu;
    public GameObject popUpHelp;

    [Header("Sounds")]
    public AudioClip doorSound;

    [Header("Text")]
    public Text scoreText;
    public Text levelText;

    [Header("Images")]
    public Image[] heart_Player;
    public Image levelImage;

    [Header("Door")]
    public GameObject[] doorButton = new GameObject[4];

    public int gameLife;//{get; set; }//Base on game mode: Easy : 3 life , Normal:2 life , Hard :1
    public int score { get; set; }
    public int heartCount_Player; //{ get; set; }
    public bool pauseGame { get; set; }
    public DoorController[] doors = new DoorController[4]
    {
        new DoorController(),
        new DoorController(),
        new DoorController(),
        new DoorController()
    };
        
    [HideInInspector]
    public bool gameOver = false;

    //private DoorController npc;

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
   // [HideInInspector]
    private AnswerSet[] Resources = new AnswerSet[10];
    //{
    //    new AnswerSet("Lý Thường Kiệt là hậu duệ của vị vua nổi tiếng nào?",
    //                  "Ngô Quyền","Lê Hoàn","Lý Công Uẩn" ,"Cả ba đáp án đều sai",0),
    //    new AnswerSet("Trước khi trở thành quan thái úy của triều đình, Lý Thường Kiệt là?",
    //                  "Quan văn","Quan võ","Thái giám" ,"Chưa từng làm quan trước đó",2),
    //    new AnswerSet("Tinh thần chủ động đối phó với quân Tống của nhà Lý thể hiện rõ trong chủ trương",
    //                  "Vườn không nhà trống","Ngồi yên đợi giặc không bằng đem quân đánh trước để chặn mũi nhọn của giặc","Lập phòng tuyến chắc chắn để chặn giặc" ,"Tích cực chuẩn bị lương thảo, vũ khí, luyện quân để chống lại thế mạnh của giặc",1),
    //    new AnswerSet("Khi biết quân Tống sang xâm lược, Lý Thường Kiệt làm gì",
    //                  "Tấn công thành Ung Châu","Tấn công thành Liêm Châu","Dựng phòng tuyến Như Nguyệt" ,"Cả A và B",3),
    //    new AnswerSet("Phương châm chiến lược của ta trong Đông-Xuân 1953-1954 là gì?", "“Đánh nhanh, thắng nhanh”", "“Đánh chắc, thắng chắc”","“Đánh vào những nơi ta cho là chắc thắng”", "“Tích cực, chủ động, cơ động, linh hoạt”, “Đánh ăn chắc Đánh chắc thắng”", 3),
    //    new AnswerSet("Nơi nào diễn ra trận chiến đấu giằng co và ác liệt nhất trong chiến dịch Điện Biên Phủ","Cứ điểm Him Lam", "Sân bay Mường Thanh", "Đồi A1", "Sở chỉ huy Đờ Cát-tơ- ri", 2),
    //    new AnswerSet("Nội dung nào không phải là mục tiêu cuộc đấu tranh của nhân dân miền Nam trong những ngày đầu chống Mĩ - Diệm?", "Đòi thi hành hiệp định Giơnevơ", "Bảo vệ hòa bình", "Giữ gìn và phát triển lực lượng", "Lật đổ chính quyền Mĩ - Diệm", 3),
    //    new AnswerSet("Điểm khác nhau giữa “Chiến tranh đặc biệt” và “Việt Nam hóa chiến tranh” là gì?", "Hình thức chiến tranh thực dân mới của Mỹ", "Có sự phối hợp đáng kể của lực lượng chiến đấu Mỹ", "Dưới sự chỉ huy của hệ thống cố vấn quân sự Mỹ", "Sử dụng lực lượng chủ yếu là quân nguỵ", 1),
    //    new AnswerSet("Thắng lợi lớn nhất của quân và dân miền Bắc trong trận “Điện Biên Phủ trên không” là gì?", "Buộc Mĩ kí hiệp định Pa-ri về chấm dứt chiến tranh lập lại hòa bình ở Việt Nam", "Buộc Mĩ phải tuyên bố ngừng hán các hoạt độríg chống phá miền Bắc", "Đánh bại âm mưu phá hoại công cuộc xây dựng CNXH ở miền Bắc", "Đánh bại âm mưu ngăn chặn sự chi viện của miền Bắc cho miền Nam,Lào, Campuchia", 0),
    //    new AnswerSet("abc","d", "e", "f","g",3),
    //};

    public List<AnswerSet> randomQASet = new List<AnswerSet>();


	// Use this for initialization
	void Start ()
    {
        //Debug.Log("Run Final GameManager");

        levelText.text = "Màn chơi cuối";

        if (LevelManager.instance.wasRandom == false)
        {
            DataBaseLoader.LoadDatabase(4, Resources);
            RandomResource(); //Random question and set into 4 doors

            LevelManager.instance.wasRandom = true;
            //LevelManager.instance.scoreInOneScene = 0;
            //LevelManager.instance.playerHealth = 3;
            LevelManager.instance.heartCount_Player = LevelManager.instance.playerHealth;
            LevelManager.instance.heartCount_Dof = 3;
            LevelManager.instance.doorSound = doorSound;

            for (int i = 0; i < 4; i++)
            {
                LevelManager.instance.doors[i] = doors[i];
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (LevelManager.instance.doors[i].isCompleted)
                    doorButton[i].SetActive(false);
            }
        }

       score = LevelManager.instance.scoreInOneScene;
        scoreText.text = "Score:" + score.ToString();
        heartCount_Player = LevelManager.instance.heartCount_Player;
        gameLife = LevelManager.instance.playerHealth;


        ////Display the player's life
        //for (int i = heartCount_Player - 1; i < gameLife - 1; i++)
        //{
        //    heart_Player[i + 1].gameObject.SetActive(false);
        //}

        for (int i = 0; i < heartCount_Player; i++)
        {
            heart_Player[i].gameObject.SetActive(true);
        }
	}

    


    

    public void ExitToMain()
    {
        Application.LoadLevel("Menu");
    }

    public void ResumeGame()
    {
        popUpMenu.SetActive(false);
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

    private void HideLevelIntro()
    {
        levelImage.gameObject.SetActive(false);
        levelText.gameObject.SetActive(false);
    }

    public void RestartLevel()
    {
        LevelManager.instance.wasRandom = false;
        LevelManager.instance.scoreInOneScene = 0;
        LevelManager.instance.heartCount_Player = gameLife;
        LevelManager.instance.heartCount_Dof = 3;

        Application.LoadLevel(Application.loadedLevel);
    }

    private bool IsExists(int[] randomArray, int x)
    {
        for (int i = 0; i < randomArray.Length; i++)
        {
            if (x == randomArray[i]) return true;
        }
        return false;
    }
   
     private void RandomResource()
    {
        const int questionCount = 10;
        int[] randomArray = new int[questionCount];
        int length = 0;
        int randomIndex = 0;
        //doors = GameObject.FindGameObjectsWithTag("Door");
         for (int i = 0; i < doors.Length; i++)
         {
             for (int j = 0; j < 2; j++)
             {
                 do
                 {
                     //Keep random the index 
                     randomIndex = Random.Range(0, questionCount);
                 }
                 while (IsExists(randomArray, randomIndex));

                 //Add the new randomIndex to the random index array
                 randomArray[length++] = randomIndex;
                
                 //Add the QASetSource to the randomMainQASet list
                 randomQASet.Add(Resources[randomIndex]);

             }
            
             doors[i].AddQA(randomQASet);
             //Debug.Log(doors[0].QASetList[0].question);
             randomQASet.Clear();
         }
         

    }

}
