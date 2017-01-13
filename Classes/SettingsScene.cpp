#include "SettingsScene.h"
Scene* SettingsScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingsScene::create();
	scene->addChild(layer);
	return scene;
}

bool SettingsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	createBackground();
	createBackButton();
	createMusicVolumeSlider();
	createBGSoundCheckBox();
	auto menu = Menu::create(backButton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	return true;
}

void SettingsScene::createBackground()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto backgroundImage = Sprite::create(SETTINGS_BACKROUND_IMAGE);
	backgroundImage->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	backgroundImage->setScale(0.9f);
	this->addChild(backgroundImage, -1);
}

//========================================UI
void SettingsScene::createBGSoundCheckBox() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto sliderLabel = CreateTextLabel("Background sound enabled",
		SETTINGS_LABEL_FONT, SETTINGS_LABEL_SIZE / 2,
		Vec2(origin.x + visibleSize.width * 1.5 / 10, origin.y + visibleSize.height * 8 / 10));

	bgSoundCB = CheckBox::create("CBdisabledYellow.png", "vote.png", Widget::TextureResType::LOCAL);
	bgSoundCB->setAnchorPoint(Vec2(0, 0.5));
	bgSoundCB->setPosition(sliderLabel->getPosition() + Vec2(220, 6));
	setBGSoundCheckBoxState();
	bgSoundCB->setScale(0.03f);
	bgSoundCB->addEventListener(CC_CALLBACK_1(SettingsScene::selectedEvent, this));
	this->addChild(bgSoundCB);
}

void SettingsScene::setBGSoundCheckBoxState() {
	if (!AudioManager::isBackgroundMusicPlaying()) {
		bgSoundCB->setSelectedState(false);
	}
	else {
		bgSoundCB->setSelectedState(true);
		slider->setPercent(AudioManager::getBackgroundAudioVolume() * 100);
	}
	setSliderState();
}

void SettingsScene::createBackButton() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto button = Label::createWithTTF("Back", SETTINGS_LABEL_FONT, SETTINGS_LABEL_SIZE);
	button->setTextColor(ccc4(215, 255, 0, 255));
	backButton = MenuItemLabel::create(button, CC_CALLBACK_1(SettingsScene::mainMenuCallback, this));
	backButton->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 4));

}

void SettingsScene::createMusicVolumeSlider() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto sliderLabel = CreateTextLabel("Background sound volume",
		SETTINGS_LABEL_FONT, SETTINGS_LABEL_SIZE / 2, Vec2(origin.x + visibleSize.width * 1.5 / 10, origin.y + visibleSize.height * 8 / 10 - 70));

	slider = Slider::create();
	slider->setAnchorPoint(Vec2(0, 0.5));
	slider->loadBarTexture("slider/slider-track.png");
	slider->loadSlidBallTextures("slider/slider-cap.png", "slider/slider-cap.png", "");
	slider->loadProgressBarTexture("slider/slider-track-fill.png");
	slider->setPercent(AudioManager::getBackgroundAudioVolume() * 100);
	slider->setPosition(sliderLabel->getPosition() + Vec2(sliderLabel->getContentSize().width + 20, 0));
	slider->addEventListener([&](Ref* sender, Slider::EventType type) {
		if (type == Slider::EventType::ON_PERCENTAGE_CHANGED) {
			AudioManager::setBackgroundAudioVolume((float)slider->getPercent() / 100);
		}
	});
	this->addChild(slider);
}

void SettingsScene::setSliderState()
{
	if (bgSoundCB->getSelectedState()) {
		slider->setEnabled(true);
		slider->setPercent(AudioManager::getBackgroundAudioVolume() * 100);
	}
	else
	{
		slider->setEnabled(false);
	}
}

//======================================Callbacks
void SettingsScene::selectedEvent(Ref* pSender)
{
	if (!AudioManager::isBackgroundMusicPlaying())
		AudioManager::playBackgroundAudio();
	else
		AudioManager::stopBackgroundAudio();
	setSliderState();
}

void SettingsScene::mainMenuCallback(Ref* pSender)
{
	SettingsConfRW::writeBGMusicPlaying(AudioManager::isBackgroundMusicPlaying());
	SettingsConfRW::writeBGMusicVolume(AudioManager::getBackgroundAudioVolume());
	//======================================
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

//======================================================upd
Label *SettingsScene::CreateTextLabel(char *text, char *ff, int fsize, Vec2 pos)
{
	Label *label = Label::createWithTTF(text, ff, fsize);
	label->setAnchorPoint(Vec2(0, 0.5));
	label->setPosition(pos);
	this->addChild(label, 1, "text_label");
	return label;
}