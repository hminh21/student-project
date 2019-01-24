using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Data.SqlClient;
using System.Data.Common;

public class DisableAllIds : MonoBehaviour {
    public Button[] allIds;
    public void DisableIDs()
    {
        for(int i=0;i<6;i++)
        {
            allIds[i].gameObject.SetActive(false);
        }
    }
}
