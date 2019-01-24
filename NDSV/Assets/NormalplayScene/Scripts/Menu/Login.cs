using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Data.SqlClient;
using System.Data.Common;

public class Login : MonoBehaviour {
    public Button[] allIds;

    public void LoginAnID()
    {      
        string connectString = @"Data Source=127.0.0.1;Initial Catalog=NDSV;Persist Security Info=True;User ID=sa;Password=1";
        SqlConnection conn = new SqlConnection(connectString);
        conn.Open();
        string sql = "Select Username from PLAYER";
        SqlCommand cmd = new SqlCommand();
        cmd.Connection = conn;
        cmd.CommandText = sql;
        using (DbDataReader reader = cmd.ExecuteReader())
        {
            if (reader.HasRows)
            {
                int i = 0;
                while (reader.Read())
                {
                    int usernameIndex = reader.GetOrdinal("Username");
                    string username = reader.GetString(usernameIndex);
                    allIds[i].gameObject.SetActive(true);
                    allIds[i].GetComponent<Button>().GetComponentInChildren<Text>().text = username;
                    i++;
                }
            }
        }
    }
}
