#include "Prueba.h"
#include "Global.h"
#include "MainMenuScene.h"

//super movida de la leche para hacer variables globales xD


int Global::_test;
USING_NS_CC;

Scene* Prueba::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Prueba::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Prueba::startGame(Ref *pSender) {
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

bool Prueba::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Global::_test = 0;

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Creating Menu

	//auto menuTitle = MenuItemImage::create("images/MainMenuScreen/Game_Title.png", "images/MainMenuScreen/Game_Title.png");

	auto playItem = MenuItemImage::create("images/MainMenuScreen/play.jpg", "images/MainMenuScreen/play_click.jpg", CC_CALLBACK_1(Prueba::startGame, this));

	auto play = Menu::create(playItem, NULL);

	play->setPosition(Vec2(560, 100));

	addChild(play, 1);


	auto background = Sprite::create("images/hogwarts.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	//audio

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/ButtonClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Crash.wav");


	// Inicializando el Sprite del jugador




	//background music

	/*auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (audio->isBackgroundMusicPlaying()==false)
	{
	audio->preloadBackgroundMusic("audio/Music.mp3");
	audio->playBackgroundMusic("audio/Music.mp3", true);
	musicMuted = false;
	}*/

	return true;
}
