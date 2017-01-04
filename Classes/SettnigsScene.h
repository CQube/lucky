#ifndef __SETTINGS_SCENE_H__
#define __SETTINGS_SCENE_H__

#include "cocos2d.h"
#include "MainMenuScene.h"
#include <ui/UICheckBox.h>
USING_NS_CC;
using namespace ui;

#define SETTINGS_LABEL_FONT "fonts/Enchanted Land cyr-lat.ttf"
#define SETTINGS_LABEL_SIZE 60
#define SETTINGS_BACKROUND_IMAGE "backgrounds/settings-background.jpg"

class SettnigsScene : public cocos2d::Layer
{
private:
	ui::CheckBox						 *bgSoundCB;
	Vector<MenuItem*>				  MenuItems;
public:
	//=============================SceneCreators
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SettnigsScene);
	//=============================
	void createBackground();
	//=============================Callbacks
	void mainMenuCallback(Ref* pSender);
	void selectedEvent(Ref* pSender);
	//=============================UI Elements
	void createBGSoundCheckBox();
};

#endif //__SETTINGS_SCENE_H__