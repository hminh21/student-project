using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayBackgroundMusic : MonoBehaviour {

	// Use this for initialization
	void Start () 
    {
        NotDestroyMusic.Instance.gameObject.SetActive(true);
	}
	

}
