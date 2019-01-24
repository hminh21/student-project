using UnityEngine;
using System.Collections;
using System.Collections.Generic;

[System.Serializable]
public class DoorController
{
    private string levelName;
    public int QASetCount { get; set; }
    public List<AnswerSet> QASetList = new List<AnswerSet>();
    public string dummyText { get; set; }

    public bool isCompleted { get; set; }
    public DoorController()
    {
        levelName = "Hồ Chí Minh";
        dummyText = "Ngươi hãy trả lời 2 câu hỏi của ta, nếu như trả lời sai ngươi sẽ phải trả giá.\n(Ấn Space để tiếp tục)";
        isCompleted = false;
    }

    public void AddQA(List<AnswerSet> list)
    {
        foreach (var set in list)
        {
            QASetList.Add(set);
        }

        QASetCount = list.Count;
    }
}
