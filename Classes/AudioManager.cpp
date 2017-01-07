#include "AudioManager.h"
int AudioManager::backgound_audioID;
bool AudioManager::_playing;

void AudioManager::playBackgroundAudio() {
	backgound_audioID = AudioEngine::play2d(BACKGROUND_SOUND, true, 1.0f);
	_playing = true;
}

void AudioManager::stopBackgroundAudio(){
	AudioEngine::stop(backgound_audioID);
	_playing = false;
}

void AudioManager::pauseBackgroundAudio(){
	AudioEngine::pause(backgound_audioID);
	_playing = false;
}

void AudioManager::resumeBackgroundAudio(){
	AudioEngine::resume(backgound_audioID);
	_playing = true;
}

void AudioManager::setBackgroundAudioVolume(float value){
	AudioEngine::setVolume(backgound_audioID, value);
}

float AudioManager::getBackgroundAudioVolume() {
	return AudioEngine::getVolume(backgound_audioID);
}

void AudioManager::endAudio() {
	_playing = false;
	AudioEngine::end();
}

bool AudioManager::isBackgroundMusicPlaying() {
	return _playing;
}
