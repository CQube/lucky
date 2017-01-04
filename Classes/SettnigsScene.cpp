#include "SettnigsScene.h"
Scene* SettnigsScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettnigsScene::create();
	scene->addChild(layer);
	return scene;
}

bool SettnigsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	createBackground();
	//============================Back button
	auto button = Label::createWithTTF("Back", MAIN_MENU_LABEL_FONT, MAIN_MENU_LABEL_SIZE);
	button->setTextColor(ccc4(215, 255, 0, 255));
	auto playButton = MenuItemLabel::create(button, CC_CALLBACK_1(SettnigsScene::mainMenuCallback, this));
	playButton->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 4));
	auto menu = Menu::create(playButton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	
	createBGSoundCheckBox();
	
	return true;
}

void SettnigsScene::mainMenuCallback(Ref* pSender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void SettnigsScene::createBackground()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto backgroundImage = Sprite::create(SETTINGS_BACKROUND_IMAGE);
	backgroundImage->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	backgroundImage->setScale(0.9f);
	this->addChild(backgroundImage, -1);
}

void SettnigsScene::createBGSoundCheckBox() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto bgSoundCB = CheckBox::create("CBdisabledYellow.png", "vote.png", Widget::TextureResType::LOCAL);
	bgSoundCB->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	bgSoundCB->setSelectedState(true);
	bgSoundCB->setScale(0.1f);
	//bgSoundCB->addEventListener(CC_CALLBACK_2(SettnigsScene::selectedEvent, this));
	this->addChild(bgSoundCB);
}

void SettnigsScene::selectedEvent(Ref* pSender)
{
	if (!AudioManager::isBackgroundMusicPlaying())
		AudioManager::playBackgroundAudio();
	else
		AudioManager::stopBackgroundAudio();
}