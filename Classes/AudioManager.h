#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__
#include <AudioEngine.h>
#include <SimpleAudioEngine.h>
using namespace cocos2d::experimental;
#define BACKGROUND_SOUND "Sounds/Swingrowers feat Gypsy Hill - The Queen Of Swing (High Quality).mp3" //Gorillaz_-_Kids_With_Guns.wav"

class AudioManager
{
private:
	static int		   backgound_audioID;
	static bool					_playing;
public:
	static void playBackgroundAudio();
	static void stopBackgroundAudio();
	static void pauseBackgroundAudio();
	static void resumeBackgroundAudio();
	static void setBackgroundAudioVolume(float value);
	static float getBackgroundAudioVolume();
	static bool isBackgroundMusicPlaying();
	static void endAudio();
};

#endif //__AUDIO_MANAGER_H__
