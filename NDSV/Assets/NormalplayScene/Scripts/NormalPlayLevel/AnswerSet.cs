using UnityEngine;
using System.Collections;
using System.Data;
using System.Data.SqlClient;
using System.Data.Common;

[System.Serializable]
public class AnswerSet  
{
    public AnswerSet()
    {

    }


    public AnswerSet(string p1, string p2, string p3, string p4, string p5, int p6)
    {
        // TODO: Complete member initialization
        question = p1;
        answerA = p2;
        answerB = p3;
        answerC = p4;
        answerD = p5;
        trueAnswer = p6;

       
    }
    public string question;
        public string answerA { get; set; }
        public string answerB { get; set; }
        public string answerC { get; set; }
        public string answerD { get; set; }
        public int trueAnswer { get; set; } 
}
