using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Data.SqlClient;
using System.Data.Common;
using System.Data;
using System;
using System.Threading;

public class IDCreatScript : MonoBehaviour
{

    public InputField idField;
    public Text notice;
    public Button arrow;
    public void CreateNewID()
    {
        if (idField.text.Length > 0 && idField.text.Length <= 15)
        {
            string connectString = @"Data Source=127.0.0.1;Initial Catalog=NDSV;Persist Security Info=True;User ID=sa;Password=1";
            SqlConnection conn = new SqlConnection(connectString);
            conn.Open();
           // try
            //{
                // Tạo một đối tượng Command để gọi thủ tục Get_Employee_Info.
                SqlCommand cmd = new SqlCommand("sp_SignUp", conn);

                // Kiểu của Command là StoredProcedure
                cmd.CommandType = CommandType.StoredProcedure;

                //Thêm tham số username là username người dùng nhập
                cmd.Parameters.Add("@username", SqlDbType.NChar).Value = idField.text;


                //thực thi
                cmd.ExecuteNonQuery();
               // idField.text = "asdasdasdasdasd";
                /////////
                PlayerPrefs.SetString("CurrentPlayer", idField.text);

                string sql = "Select PlayerID from PLAYER where Username = N'" + idField.text + "'";
                SqlCommand cmd2 = new SqlCommand();
                cmd2.Connection = conn;
                cmd2.CommandText = sql;
                using (DbDataReader reader = cmd2.ExecuteReader())
                {
                    if (reader.HasRows)
                    {
                        while (reader.Read())
                        {
                            int idIndex = reader.GetOrdinal("PlayerID");
                            int id = Convert.ToInt16(reader.GetValue(idIndex));
                            LevelManager.instance.playerID = id;
                        }
                    }
                }

                
            //}
            //catch (Exception e)
            //{
            //    Console.WriteLine("Error: " + e);
            //    Console.WriteLine(e.StackTrace);
            //}
            //finally
            //{
            //    conn.Close();
            //    conn.Dispose();
            //}
                conn.Close();
                conn.Dispose();
            Application.LoadLevel("Intro");
        }
        else
        {  
            StartCoroutine(Notice());
        }
    }
    IEnumerator Notice()
    {
        notice.text = "Tên tài khoản của bạn có độ dài vượt quá 15!";
        arrow.gameObject.SetActive(true);
        yield return new WaitForSeconds(1);
        arrow.gameObject.SetActive(false);
        yield return new WaitForSeconds(1);
        arrow.gameObject.SetActive(true);
        yield return new WaitForSeconds(1);
        arrow.gameObject.SetActive(false);
        notice.text = "Lưu ý: tên tài khoản có độ dài không được vượt quá 15!";
    }

    private void Start()
    {
        if (NotDestroyMusic.Instance != null)
        {
            NotDestroyMusic.Instance.gameObject.SetActive(false);
        }
        
    }
}