using UnityEngine;
using System.Collections;
using System.Data.SqlClient;
    class DBUltils
    {
        public static SqlConnection GetDBConnection()
        {
            string datasource = "127.0.0.1";

            string database = "NDSV";
            string username = "sa";
            string password = "1";

            return DBSQLServerUltils.GetDBConnection(datasource, database, username, password);
        }
    }
