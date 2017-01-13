#ifndef __LOADING_FRAME_H__
#define __LOADING_FRAME_H__
#include "cocos2d.h"
#include "MainMenuScene.h"
#include "SettingsConfRW.h"
#define LOADING_FRAME_BACKROUND_IMAGE "backgrounds/loading-frame-backgound.jpg"
USING_NS_CC;

class LoadingFrame : public cocos2d::Layer
{
public: 
	//=================SceneCreators
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(LoadingFrame);
	//=================BG
	void createBackground();
	//=================changeScene
	void runMainMenuScene(float dt);
	LoadingBar* createLoadingBar();
	//=================applyDefaults
	void applyDefaults();
	void applyBGMPlaying();
	void applyBGMVolume();
};

#endif //__LOADING_FRAME_H__