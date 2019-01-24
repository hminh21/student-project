using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Video;
using System.Collections;

public class StreamVideo : MonoBehaviour {
    public RawImage image;
    public VideoClip videoToPlay;

    private VideoPlayer videoPlayer;
    private VideoSource videoSouce;

    private AudioSource audioSource;
    void Start () {
        Application.runInBackground = true;
        StartCoroutine(playVideo());
    }
    IEnumerator playVideo()
    {
        videoPlayer = gameObject.AddComponent<VideoPlayer>();
        audioSource = gameObject.AddComponent<AudioSource>();

        videoPlayer.playOnAwake = false;
        audioSource.playOnAwake = false;
        audioSource.Pause();

        videoPlayer.source = VideoSource.VideoClip;

        videoPlayer.audioOutputMode = VideoAudioOutputMode.AudioSource;

        videoPlayer.EnableAudioTrack(0, true);
        videoPlayer.SetTargetAudioSource(0, audioSource);

        videoPlayer.clip = videoToPlay;
        videoPlayer.Prepare();

        WaitForSeconds waitTime = new WaitForSeconds(1);
        while(!videoPlayer.isPrepared)
        {
            yield return waitTime;
            break;
        }
        image.texture = videoPlayer.texture;
        videoPlayer.Play();
        audioSource.Play();
        while(videoPlayer.isPlaying)
        {
            yield return null;
        }
        if(!videoPlayer.isPlaying)
        {
            Application.LoadLevel("Menu");
        }
    }
}
