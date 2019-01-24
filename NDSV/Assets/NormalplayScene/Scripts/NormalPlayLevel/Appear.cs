using UnityEngine;
using System.Collections;

public class Appear : MonoBehaviour {

    private BoxCollider2D boxCollider2D;
	// Use this for initialization
	void Start () 
    {
        boxCollider2D = GetComponent<BoxCollider2D>();


	}
	
    //Check if the player moved out the time hole
    private void OnTriggerExit2D(Collider2D other)
    {
        if (other.tag != "User") return;

        //Find the time hole gameobject and get the animator component
        GameObject timeHole = GameObject.FindGameObjectWithTag("TimeHole");
        Animator timeHoleAnimator =timeHole.GetComponent<Animator>();
        if (timeHoleAnimator == null) return;

        //Play the disspear animation
        timeHoleAnimator.SetTrigger("playerInHole");

        //Destroy the time Hole gameObject
        Destroy(timeHole, 1f);

        boxCollider2D.enabled = false;
    }
	
}
