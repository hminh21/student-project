﻿using UnityEngine;
using System.Collections;
using System.Data.SqlClient;
public class DBSQLServerUltils
{
    public static SqlConnection
            GetDBConnection(string datasource, string database, string username, string password)
    {
        //
        // Data Source=TRAN-VMWARE\SQLEXPRESS;Initial Catalog=simplehr;Persist Security Info=True;User ID=sa;Password=12345
        //
        string connString = @"Data Source=" + datasource + ";Initial Catalog="
                    + database + ";Persist Security Info=True;User ID=" + username + ";Password=" + password;

        SqlConnection conn = new SqlConnection(connString);

        return conn;
    }

}