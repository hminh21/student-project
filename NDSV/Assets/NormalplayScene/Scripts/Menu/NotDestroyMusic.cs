using UnityEngine;
using System.Collections;

public class NotDestroyMusic : MonoBehaviour {

    //tránh lặp khi chuyển scene -> dùng unity singleton
    private static NotDestroyMusic instance = null;
    public static  NotDestroyMusic Instance
    {
        get { return instance; }
    }

	void Awake()
    {
        if (instance != null & instance != this) {
            Destroy(this.gameObject);
            return;
        } else {
            instance = this;
        }
        DontDestroyOnLoad(transform.gameObject);//giữ nhạc khi chuyển scene
        
    }

}
