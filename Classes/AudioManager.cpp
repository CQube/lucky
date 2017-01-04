#include "AudioManager.h"

void AudioManager::playBackgroundAudio() {
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(BACKGROUND_SOUND, true);
}

void AudioManager::stopBackgroundAudio(){
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void AudioManager::pauseBackgroundAudio(){
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AudioManager::resumeBackgroundAudio(){
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AudioManager::setBackgroundAudioVolume(float value){
	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(value);
}

void AudioManager::endAudio() {
	CocosDenshion::SimpleAudioEngine::getInstance()->end();
}

bool AudioManager::isBackgroundMusicPlaying() {
	bool playing = CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
	return playing;
}