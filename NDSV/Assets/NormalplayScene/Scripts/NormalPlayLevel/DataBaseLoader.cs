using UnityEngine;
using System.Collections;
using System.Data.SqlClient;
using System.Data.Common;
using System.Collections.Generic;
using System;
using System.Data;

public class DataBaseLoader:MonoBehaviour {

    public static void LoadDatabase(int sceneID, AnswerSet[] Resources)
    {
        //Connect to sql databse
        SqlConnection conn = DBUltils.GetDBConnection();



        conn.Open();

        Debug.Log("Connection Successfull!");
        //Query data
        string sqlQuery = "SELECT Question,AnswerA,AnswerB,AnswerC,AnswerD,RightAnswer FROM QUESTION WHERE SceneID = " + sceneID.ToString();

        SqlCommand cmd = new SqlCommand(sqlQuery, conn);

        DbDataReader reader = cmd.ExecuteReader();

        int QACount = 0;
        AnswerSet answerSet;

        if (reader.HasRows)
        {
            //Read the data and add it to the mainQASetList an subQASetList
            while (reader.Read())
            {
                int questionIndex = reader.GetOrdinal("Question");
                string questionText = reader.GetString(questionIndex);

                int answerAIndex = reader.GetOrdinal("AnswerA");
                string answerAText = reader.GetString(answerAIndex);

                int answerBIndex = reader.GetOrdinal("AnswerB");
                string answerBText = reader.GetString(answerBIndex);

                int answerCIndex = reader.GetOrdinal("AnswerC");
                string answerCText = reader.GetString(answerCIndex);

                int answerDIndex = reader.GetOrdinal("AnswerD");
                string answerDText = reader.GetString(answerDIndex);

                int rightAnswerIndex = reader.GetOrdinal("RightAnswer");
                int rightAnswer = Convert.ToInt32(reader.GetValue(rightAnswerIndex));

                answerSet = new AnswerSet(questionText, answerAText, answerBText, answerCText, answerDText, rightAnswer);

                Resources[QACount++] = answerSet;
            }
        }

        conn.Close();
    }


    public static void LoadQADatabase(int sceneID, AnswerSet[] mainQASetSrc, AnswerSet[] subQASetSrc)
    {
        //Connect to sql databse
        SqlConnection conn = DBUltils.GetDBConnection();



        conn.Open();

        //Query data
        string sqlQuery = "SELECT Question,AnswerA,AnswerB,AnswerC,AnswerD,RightAnswer,isBonus FROM QUESTION WHERE SceneID = " + sceneID.ToString();

        SqlCommand cmd = new SqlCommand(sqlQuery, conn);

        DbDataReader reader = cmd.ExecuteReader();

        int mainQACount = 0;
        int subQACount = 0;
        AnswerSet answerSet;

        if (reader.HasRows)
        {
            //Read the data and add it to the mainQASetList an subQASetList
            while (reader.Read())
            {
                int questionIndex = reader.GetOrdinal("Question");
                string questionText = reader.GetString(questionIndex);

                int answerAIndex = reader.GetOrdinal("AnswerA");
                string answerAText = reader.GetString(answerAIndex);

                int answerBIndex = reader.GetOrdinal("AnswerB");
                string answerBText = reader.GetString(answerBIndex);

                int answerCIndex = reader.GetOrdinal("AnswerC");
                string answerCText = reader.GetString(answerCIndex);

                int answerDIndex = reader.GetOrdinal("AnswerD");
                string answerDText = reader.GetString(answerDIndex);

                int rightAnswerIndex = reader.GetOrdinal("RightAnswer");
                int rightAnswer = Convert.ToInt32(reader.GetValue(rightAnswerIndex));

                int isBonusIndex = reader.GetOrdinal("isBonus");
                int isBonus = Convert.ToInt32(reader.GetValue(isBonusIndex));

                answerSet = new AnswerSet(questionText, answerAText, answerBText, answerCText, answerDText, rightAnswer);
                if (isBonus == 0) //This is the main QA set
                {
                    mainQASetSrc[mainQACount++] = answerSet;
                    

                }
                else if (isBonus == 1) // This is the sub QA set
                {
                    subQASetSrc[subQACount++] = answerSet;
                    
                }

            }
        }

        conn.Close();
    }


    public static void LoadResultDataBase(int playerID,  bool[]  isCompleted)
    {
        //Connect to sql database
        SqlConnection conn = DBUltils.GetDBConnection();

        conn.Open();

        //Query data
        string sqlQuery = "SELECT isCompleted FROM RESULT WHERE  PlayerID = " + playerID;

        SqlCommand cmd = new SqlCommand(sqlQuery, conn);
        DbDataReader reader = cmd.ExecuteReader();

        int isCompletedCount = 0;

        if (reader.HasRows)
        {
            while (reader.Read())
            {
                int wasCompletedIndex = reader.GetOrdinal("isCompleted");
                isCompleted[isCompletedCount++] = Convert.ToBoolean(reader.GetValue(wasCompletedIndex));
            }
        }

        conn.Close();
    }

    public static void SaveGameInNormalScene(int playerID, int sceneID,int score , bool isCompleted)
    {
        //@playerID int
        //@score int
        //@sceneID int
        //@isComplete bool


        //Connect to sql database
        SqlConnection conn = DBUltils.GetDBConnection();

        conn.Open();
        SqlCommand cmd = new SqlCommand("sp_UpdateStatus", conn);

        //Set type for command
        cmd.CommandType = CommandType.StoredProcedure;

        //Add parameters and set value for procedure
        cmd.Parameters.Add("@playerID", SqlDbType.Int).Value = playerID;
        cmd.Parameters.Add("@sceneID", SqlDbType.Int).Value = sceneID;
        cmd.Parameters.Add("@score", SqlDbType.Int).Value = score;
        cmd.Parameters.Add("@isCompleted", SqlDbType.Bit).Value = isCompleted ? 1 : 0;

        //Execute procedure
        cmd.ExecuteNonQuery();
        
        conn.Close();

    }

    //This function will create a new game for player
    public static void CreateNewGame(int playerID )
    {
        //@playerID int
        //@score int
        //@sceneID int
        //@isComplete bool
        //Connect to sql database
        SqlConnection conn = DBUltils.GetDBConnection();

        conn.Open();
        SqlCommand cmd = new SqlCommand("sp_UpdateStatus", conn);

        //Set type for command
        cmd.CommandType = CommandType.StoredProcedure;

         SqlParameter playerIDPar=  cmd.Parameters.Add("@playerID", SqlDbType.Int);
         SqlParameter sceneIDPar = cmd.Parameters.Add("@sceneID", SqlDbType.Int);
         SqlParameter scorePar = cmd.Parameters.Add("@score", SqlDbType.Int);
         SqlParameter isCompleted = cmd.Parameters.Add("@isCompleted", SqlDbType.Bit);
        for (int i = 0; i < 5; i++ )
        {
            //Add parameters and set value for procedure
            playerIDPar.Value = playerID;
            sceneIDPar.Value = i;
            scorePar.Value = 0;
            isCompleted.Value = 0;

            //Execute procedure
            cmd.ExecuteNonQuery();
        }
        
        conn.Close();
    }

    //Load playerID base on the user name
    public static int LoadPlayerID(string playerName)
    {

        int playerID = 0;

        //Connect to sql database
        SqlConnection conn = DBUltils.GetDBConnection();

        conn.Open();

        //Create query string
        string sqlQuery = "SELECT playerID FROM PLAYER WHERE Username = '" + playerName+"'";
        SqlCommand cmd = new SqlCommand(sqlQuery, conn);

        //Query the database
        DbDataReader reader = cmd.ExecuteReader();
        if (reader.HasRows)
        {
            while (reader.Read())
            {
                int playerIdIndex = reader.GetOrdinal("playerID");
                playerID = Convert.ToInt32(reader.GetValue(playerIdIndex));
            }
        }
        conn.Close();
        return playerID;
    }

    public static  void SaveGameModeToDb(int playerID, int gameLife)
    {
        SqlConnection conn = DBUltils.GetDBConnection();

        conn.Open();

        string sqlQuery = "UPDATE PLAYER SET GameLife = " + gameLife + "WHERE PlayerID = " + playerID;

        SqlCommand cmd = new SqlCommand(sqlQuery, conn);
        cmd.ExecuteNonQuery();

        conn.Close();
    }

    public static int LoadGameMode(int playerID)
    {

        int gameLife = 0;
        SqlConnection conn = DBUltils.GetDBConnection();

        conn.Open();

        string sqlQuery = "SELECT GameLife FROM PLAYER WHERE PlayerID =" + playerID;
        SqlCommand cmd = new SqlCommand(sqlQuery, conn);

        DbDataReader reader = cmd.ExecuteReader();
        if (reader.HasRows)
        {
            while (reader.Read())
            {
                int gameLifeIndex = reader.GetOrdinal("GameLife");
                gameLife = Convert.ToInt32(reader.GetValue(gameLife));
            }
        }

        conn.Close();

        return gameLife;

        
    }

    public static void LoadScoreAllScenes(int playerID, ref int[] scoreScene)
    {
        SqlConnection conn = DBUltils.GetDBConnection();

        conn.Open();

        string sqlQuery = "SELECT Score, SceneID FROM RESULT WHERE PlayerID = " + playerID;

        SqlCommand cmd = new SqlCommand(sqlQuery, conn);


        DbDataReader reader = cmd.ExecuteReader();

        if (reader.HasRows)
        {
            while (reader.Read())
            {
                int sceneIDIndex = reader.GetOrdinal("SceneID");
                int sceneID = Convert.ToInt32(reader.GetValue(sceneIDIndex));

                int scoreIndex = reader.GetOrdinal("Score");
                int score = Convert.ToInt32(reader.GetValue(scoreIndex));

                if (sceneID < scoreScene.Length)
                    scoreScene[sceneID] = score;
            }
        }

        conn.Close();

        //Load totalscore
        conn = DBUltils.GetDBConnection();
        conn.Open();

        sqlQuery = "SELECT TotalScore FROM PLAYER WHERE PlayerID = " + playerID;
        cmd = new SqlCommand(sqlQuery, conn);

        reader = cmd.ExecuteReader();

        if (reader.HasRows)
        {
            while (reader.Read())
            {
                int totalScoreIndex = reader.GetOrdinal("TotalScore");
                int totalScore = Convert.ToInt32(reader.GetValue(totalScoreIndex));

                scoreScene[scoreScene.Length - 1] = totalScore;
            }
        }

        conn.Close();
    }

    public static bool LoadResultInOneScene(int playerID, int sceneID)
    {
        SqlConnection conn = DBUltils.GetDBConnection();
        bool isCompleted = false;
        conn.Open();

        string sqlQuery = "SELECT isCompleted FROM RESULT WHERE PlayerID =" + playerID + "AND SceneID = " + sceneID;
        SqlCommand cmd = new SqlCommand(sqlQuery, conn);

        DbDataReader reader = cmd.ExecuteReader();

        if (reader.HasRows)
        {
            while (reader.Read())
            {
                int isCompletedIndex = reader.GetOrdinal("isCompleted");
                isCompleted = Convert.ToBoolean(reader.GetValue(isCompletedIndex));
            }
        }

        conn.Close();

        return isCompleted;
    }

}
