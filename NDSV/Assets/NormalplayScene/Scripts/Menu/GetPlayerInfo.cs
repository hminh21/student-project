using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using System;
using System.Data;
using System.Data.SqlClient;
using System.Data.Common;
using UnityEngine;

public class GetPlayerInfo : MonoBehaviour {
    public Button[] results;
    public Text TotalScore;
    public Sprite Checkmark;
	void Start () {
        string curPlayer = PlayerPrefs.GetString("CurrentPlayer");

        string connectString = @"Data Source=127.0.0.1;Initial Catalog=NDSV;Persist Security Info=True;User ID=sa;Password=anhvip123";
        SqlConnection conn = new SqlConnection(connectString);
        conn.Open();
        
        string sql = "Select PlayerID FROM PLAYER WHERE Username = N'"+ curPlayer+"'";
        SqlCommand cmd = new SqlCommand();
        cmd.Connection = conn;
        cmd.CommandText = sql;

        int playerID = 0;
        using (DbDataReader reader = cmd.ExecuteReader())
        {
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    int playerIDIndex = reader.GetOrdinal("PlayerID");
                    playerID = Convert.ToInt16(reader.GetValue(playerIDIndex));
                }
            }
        }

        sql = "SELECT * FROM RESULT WHERE RESULT.PlayerID = " + playerID.ToString();
        cmd.CommandText = sql;
        int totalScore = 0;
        using (DbDataReader reader = cmd.ExecuteReader())
        {
            if (reader.HasRows)
            {
               
                while (reader.Read())
                {
                    int scoreIndex = reader.GetOrdinal("Score");
                    int score = Convert.ToInt16(reader.GetValue(scoreIndex));
                    int sceneIndex = reader.GetOrdinal("SceneID");
                    int sceneID = Convert.ToInt32(reader.GetValue(sceneIndex));

                    
                    results[sceneID].GetComponentInChildren<Text>().text = score.ToString();

                    int isCompletedIndex = reader.GetOrdinal("isCompleted");
                    bool isCompleted = reader.GetBoolean(isCompletedIndex);
                    if (isCompleted)
                    {
                        Debug.Log("SceneID: " + sceneID);
                        results[sceneID].image.overrideSprite = Checkmark; 
                    }
             
                    totalScore += score;

   
                }
            }
        }
        TotalScore.text = totalScore.ToString();

        conn.Close();
        conn.Dispose();
    }
}
