#include "MainMenuScene.h"

Scene* MainMenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainMenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
	createBackground();
	createButtons();
	//AudioManager::playBackgroundAudio();
	auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}
//====================================Buttons
void MainMenuScene::createButtons()
{
	createPlayButton();
	createOptionsButton();
	createExitButton();
}

void MainMenuScene::createPlayButton() {
	auto button = Label::createWithTTF("Play", MAIN_MENU_LABEL_FONT, MAIN_MENU_LABEL_SIZE);
	button->setTextColor(ccc4(215, 255, 0, 255));
	playButton = MenuItemLabel::create(button, CC_CALLBACK_1(MainMenuScene::playGameCallback, this));
	playButton->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 + playButton->getContentSize().height * 2));
	MenuItems.pushBack(playButton);
}

void MainMenuScene::createOptionsButton() {
	auto button = Label::createWithTTF("Options", MAIN_MENU_LABEL_FONT, MAIN_MENU_LABEL_SIZE);
	button->setTextColor(ccc4(215, 255, 0, 255));
	optionsButton = MenuItemLabel::create(button, CC_CALLBACK_1(MainMenuScene::optionsSceneCallback, this));
	optionsButton->setPosition(playButton->getPosition() + Vec2(0, -playButton->getContentSize().height * 1.5));
	MenuItems.pushBack(optionsButton);
}

void MainMenuScene::createExitButton() {
	auto button = Label::createWithTTF("Exit", MAIN_MENU_LABEL_FONT, MAIN_MENU_LABEL_SIZE);
	button->setTextColor(ccc4(215, 255, 0, 255));
	exitButton = MenuItemLabel::create(button, CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	exitButton->setPosition(optionsButton->getPosition() + Vec2(0, -optionsButton->getContentSize().height * 1.5));
	MenuItems.pushBack(exitButton);
}
//==============================Background
void MainMenuScene::createBackground()
{
	auto backgroundImage = Sprite::create(MAIN_MENU_BACKROUND_IMAGE);
	backgroundImage->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	backgroundImage->setScale(2);
	this->addChild(backgroundImage, -1);
}

//==================================Functions to CALLBACK

void MainMenuScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif   
}

void MainMenuScene::playGameCallback(Ref* pSender)
{

}

void MainMenuScene::optionsSceneCallback(Ref* pSender)
{
	auto scene = SettnigsScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

//==============implementation
MainMenuScene* MainMenuScene::create()
{
	while (1) {
		MainMenuScene *pRet = new(std::nothrow) MainMenuScene();
		if (pRet && pRet->init())
		{
			pRet->autorelease();
			return pRet;
		}
		else
			delete pRet;
	}
/*	else //попыстка создания костыля во избежание вылетов(child == NULL) при переходе на сцену (test)
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}*/
}
