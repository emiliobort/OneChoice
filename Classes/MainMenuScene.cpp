#include "MainMenuScene.h"
#include "GameScene.h"
#include "Game11.h"
#include "PauseScene.h"
#include "Kao.h"
#include "OptionsScene.h"
#include "SimpleAudioEngine.h"
#include "Global.h"

USING_NS_CC;


Scene* MainMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


void MainMenuScene::Kao(Ref *pSender) {
	if (Global::musicPlayed)
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/boton1.mp3");

	auto scene = Kao::createScene();

	Director::getInstance()->replaceScene(TransitionCrossFade::create(1.0, scene));;
}

void MainMenuScene::optionScene(Ref *pSender) {
	if (Global::musicPlayed)
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/boton1.mp3");
	
	Global::phase = 0;

	auto scene = OptionsScene::createScene();

	Director::getInstance()->replaceScene(TransitionShrinkGrow::create(1.0, scene));;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{

	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Creating Menu

	//auto menuTitle = MenuItemImage::create("images/MainMenuScreen/Game_Title.png", "images/MainMenuScreen/Game_Title.png");

	auto playItem = MenuItemImage::create("images/MainMenuScreen/play.jpg", "images/MainMenuScreen/play.jpg", CC_CALLBACK_1(MainMenuScene::Kao, this));
	auto optionItem = MenuItemImage::create("images/MainMenuScreen/options.jpg", "images/MainMenuScreen/options.jpg", CC_CALLBACK_1(MainMenuScene::optionScene, this));


	auto play = Menu::create(playItem, NULL);
	auto option = Menu::create(optionItem, NULL);

	play->setPosition(Vec2(560, 100));
	option->setPosition(Vec2(780, 100));

	addChild(play, 1);
	addChild(option, 1);


	auto background = Sprite::create("images/MainMenuScreen/inicio.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	//audio

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/boton1.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/boton2.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/inicio.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/kao.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/levels.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/neo.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/egipcio.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/cesar.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/arturo.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/edison.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/hitler.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/juego/fin.mp3");





	//background music

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0);

	if (Global::musicPlayed && Global::phase != 0 || Global::phase==2)
	{
		audio->playBackgroundMusic("audio/juego/inicio.mp3",true);
		Global::phase = 0;
		audio->setBackgroundMusicVolume(0.7f);
	}

	return true;
}