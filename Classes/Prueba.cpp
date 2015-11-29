#include "Prueba.h"
#include "Global.h"
#include "MainMenuScene.h"

//Con definimos las variables globales para luego inicializarlas al valor que queramos.

int Global::_game11;
int Global::_game12;
int Global::_game13;
int Global::_game21;
int Global::_game22;
int Global::_game23;

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

	//Inicializamos las variables globales de los juegos.

	Global::_game11 = 0;
	Global::_game12 = 0;
	Global::_game13 = 0;
	Global::_game21 = 0;
	Global::_game22 = 0;
	Global::_game23 = 0;



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

	return true;
}
