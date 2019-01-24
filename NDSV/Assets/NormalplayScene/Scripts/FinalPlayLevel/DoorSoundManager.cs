using UnityEngine;
using System.Collections;

public class DoorSoundManager : MonoBehaviour {

    [Header("Door Sound")]
    public AudioClip doorSound;
	// Use this for initialization
	void Start () 
    {
        StartCoroutine(PlaySoundDoor());
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    IEnumerator PlaySoundDoor()
    {
        yield return new WaitForSeconds(0.2f);
        GetComponent<AudioSource>().PlayOneShot(doorSound);
        yield return new WaitForSeconds(doorSound.length);

        MSceneManager.instance.PlayPlayingScene();
    }
}
