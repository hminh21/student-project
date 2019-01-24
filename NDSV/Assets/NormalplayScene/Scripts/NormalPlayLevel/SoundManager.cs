using UnityEngine;
using System.Collections;

public class SoundManager : MonoBehaviour {

    public static SoundManager instance = null;

    public AudioClip playerMoveSound1, playerMoveSound2;
    public AudioSource musicSource;//Hold the background music reference
    public AudioSource efxSource;//Hold the effect sound reference
    public float lowPitchRange = 0.95f;
    public float highPitchRange = 1.05f;
    private void Awake()
    {
        //Check if instance already exists
        if (instance == null)
        {
            // If no set instance to this
            instance = this;
        }
        //If instance already exists and it's not this
        else if (instance != this)
        {
            //Then destroy this. This enforces our singleton pattern, meaning there can only ever be one instance of a GameManager.
            Destroy(gameObject);
        }

       
    }

	// Use this for initialization
	void Start ()
    {

	}
	
	public void PlaySingleClip(AudioClip clip)
    {
        efxSource.PlayOneShot(clip);
    }

    //Declare a function to random sfx, this function will choose randomly between various audio clips and slightly changes their pitch
    //The params keywords allow us to parse in a comma separted list of arguments of the same type,as specified by the parameter
    public void RandomizeSfx(params AudioClip[] clips)
    {
        //Choose a random clip to the array to play
        int randomIndex = Random.Range(0, clips.Length);

        //Random a pitch between low pitch range and high pitch range
        float randomPitch = Random.Range(lowPitchRange, highPitchRange);

        //Set the pitch of the effect sound equal to the random pitch
        efxSource.pitch = randomPitch;

        //Play the random clip chooses from the clips array
        efxSource.PlayOneShot(clips[randomIndex]);
    }
}
