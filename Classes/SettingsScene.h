#ifndef __SETTINGS_SCENE_H__
#define __SETTINGS_SCENE_H__

#include "cocos2d.h"
#include "MainMenuScene.h"
#include <ui/CocosGUI.h>
USING_NS_CC;
using namespace ui;

#define SETTINGS_LABEL_FONT "fonts/Enchanted Land cyr-lat.ttf"
#define SETTINGS_LABEL_SIZE 60
#define SETTINGS_BACKROUND_IMAGE "backgrounds/settings-background.jpg"

class SettingsScene : public cocos2d::Layer
{
private:
	MenuItem							*backButton;
	Slider									*slider;
	CheckBox							 *bgSoundCB;
	//Vector<MenuItem*>				  MenuItems;
public:
	//=============================SceneCreators
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SettingsScene);
	//=============================
	void createBackground();
	//=============================UI Elements	
	void createBGSoundCheckBox();
	void setBGSoundCheckBoxState();
	void createBackButton();
	void createMusicVolumeSlider();
	void setSliderState();
	//=============================Callbacks
	void mainMenuCallback(Ref* pSender);
	void selectedEvent(Ref* pSender);
	void sliderEvent(Ref* pSender, Event *event);
	//==================================upd
	Label *CreateTextLabel(char *text, char *ff, int fsize, Vec2 pos);
};

#endif //__SETTINGS_SCENE_H__