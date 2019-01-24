using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Data.SqlClient;
using System.Data.Common;
using System;

public class Ranking : MonoBehaviour {
    public Text usernames;
    public Text highscores;
    void Start()
    {
        string connectString = @"Data Source=127.0.0.1;Initial Catalog=NDSV;Persist Security Info=True;User ID=sa;Password=anhvip123";
        SqlConnection conn = new SqlConnection(connectString);
        conn.Open();

        string sql = "SELECT Username, TotalScore FROM PLAYER ORDER BY TOTALSCORE DESC";
        SqlCommand cmd = new SqlCommand();
        cmd.Connection = conn;
        cmd.CommandText = sql;

        //-----LẤY DỮ LIỆU TỪ TABLE-----
        using (DbDataReader reader = cmd.ExecuteReader())
        {
            if (reader.HasRows)
            {
                int ranks = 1;
                while (reader.Read())
                {
                    //lấy cột Username
                    int usernameIndex = reader.GetOrdinal("Username");
                    string username = reader.GetString(usernameIndex);

                    //lấy cột Score
                    int scoreIndex = reader.GetOrdinal("TotalScore");
                    int score = Convert.ToInt16(reader.GetValue(scoreIndex));

                    string temp = "\n\n" + ranks.ToString() + ". " + username;
                    usernames.text += temp;

                    temp = "\n\n" + score.ToString();
                    highscores.text += temp;

                    ranks++;
                }
            }
        }
    }
}
