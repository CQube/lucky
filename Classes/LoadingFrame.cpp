#include "LoadingFrame.h"

Scene* LoadingFrame::createScene()
{
	auto scene = Scene::create();
	auto layer = LoadingFrame::create();
	scene->addChild(layer);
	return scene;
}

bool LoadingFrame::init()
{
	if (!Layer::init())
	{
		return false;
	}
	applyDefaults();
	auto loadingBar = createLoadingBar();
	createBackground();
	this->schedule(schedule_selector(LoadingFrame::runMainMenuScene), 0.5f);
	loadingBar->setPercent(100);
	return true;
}

void LoadingFrame::createBackground()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto backgroundImage = Sprite::create(LOADING_FRAME_BACKROUND_IMAGE);
	backgroundImage->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	backgroundImage->setScale(1.1);
	this->addChild(backgroundImage, -1);
}

void LoadingFrame::runMainMenuScene(float dt)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(MainMenuScene::createScene());
}

LoadingBar* LoadingFrame::createLoadingBar()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto loadingBar = LoadingBar::create("slider/slider-track-fill.png", 20);
	loadingBar->setDirection(LoadingBar::Direction::LEFT);
	loadingBar->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(loadingBar);
	return loadingBar;
}

//=======================================apply defaults
void LoadingFrame::applyDefaults() 
{
	applyBGMPlaying();
}

void LoadingFrame::applyBGMPlaying() {
	if (SettingsConfRW::readBGMusicPlaying()) //if BGM playing in conf
	{
		AudioManager::playBackgroundAudio();  //play BGM
		applyBGMVolume();					  //set volume
	}
}

void LoadingFrame::applyBGMVolume()
{
	float volume = SettingsConfRW::readBGMusicVolume();
	AudioManager::setBackgroundAudioVolume(volume);
}