using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using System;
using System.Data;
using System.Data.SqlClient;
using System.Data.Common;
using UnityEngine;

public class SetCurPlayer : MonoBehaviour {

   

	public void SetPlayerButton(Button ID)
    {
        string playerName = ID.GetComponentInChildren<Text>().text;
        if (playerName != "")
        {
            PlayerPrefs.SetString("CurrentPlayer", playerName);
            LevelManager.instance.playerID = DataBaseLoader.LoadPlayerID(playerName);
            Application.LoadLevel("Menu");
            
        }
    }
}
