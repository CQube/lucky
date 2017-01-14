#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
#include "SettingsScene.h"
#include "GameMap.hpp"
#include <AudioManager.h>

using namespace cocos2d::experimental;

USING_NS_CC;
#define MAIN_MENU_LABEL_FONT "fonts/Enchanted Land cyr-lat.ttf"
#define MAIN_MENU_LABEL_SIZE 60
#define MAIN_MENU_BACKROUND_IMAGE "backgrounds/background2.png"

class MainMenuScene : public cocos2d::Layer
{
private:
	Size							visibleSize;
	Vec2								 origin;

	Vector<MenuItem*>				  MenuItems;
	MenuItemLabel					*playButton;
	MenuItemLabel				 *optionsButton;
	MenuItemLabel					*exitButton;

public:
	//=================MainMenuSceneCreators
    static cocos2d::Scene* createScene();
    virtual bool init();
	static MainMenuScene* create();
	//===============================================Buttons+Sound+Sprites
	void createPlayButton();
	void createOptionsButton();
	void createExitButton();
	void createButtons();
	void createBackground();
	//================================================Callbacks
	void playGameCallback(Ref* pSender);
	void optionsSceneCallback(Ref* pSender);
    void menuCloseCallback(cocos2d::Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
