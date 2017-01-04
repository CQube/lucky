#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__
#include <SimpleAudioEngine.h>

#define BACKGROUND_SOUND "Sounds/Gorillaz_-_Kids_With_Guns.wav"

class AudioManager
{
private:
	static CocosDenshion::SimpleAudioEngine			   *audio;
public:
	static void playBackgroundAudio();
	static void stopBackgroundAudio();
	static void pauseBackgroundAudio();
	static void resumeBackgroundAudio();
	static void setBackgroundAudioVolume(float value);
	static bool isBackgroundMusicPlaying();
	static void endAudio();
};

#endif //__AUDIO_MANAGER_H__
