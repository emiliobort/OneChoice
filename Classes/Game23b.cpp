#include "Game23b.h"
#include "GameScene.h"
#include "Game23.h"
#include "MainMenuScene.h"
#include "SelectScene.h"

USING_NS_CC;
void Game23b::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game23b::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game23b::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Game23b::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game23b::goToSelectScene(this);
	}
}

void Game23b::animfondo(float dt)
{
	switch (fasefondo)
	{
	case(1) :
		fondo->setTexture("images/Game2.3/Mal/mal1.jpg");
		fasefondo = 2;
		break;
	case(2) :
		fondo->setTexture("images/Game2.3/Mal/mal2.jpg");
		fasefondo = 3;
		break;
	case(3) :
		fondo->setTexture("images/Game2.3/Mal/mal3.jpg");
		fasefondo = 4;
		break;
	case(4) :
		fondo->setTexture("images/Game2.3/Mal/mal4.jpg");
		fasefondo = 5;
		break;
	case(5) :
		fondo->setTexture("images/Game2.3/Mal/mal5.jpg");
		fasefondo = 6;
		break;
	case(6) :
		fondo->setTexture("images/Game2.3/Mal/mal6.jpg");
		fasefondo = 7;
		break;
	case(7) :
		fondo->setTexture("images/Game2.3/Mal/mal7.jpg");
		fasefondo = 8;
		break;
	case(8) :
		fondo->setTexture("images/Game2.3/Mal/mal8.jpg");
		fasefondo = 9;
		break;
	case(9) :
		fondo->setTexture("images/Game2.3/Mal/mal9.jpg");
		fasefondo = 10;
		break;
	case(10) :
		fondo->setTexture("images/Game2.3/Mal/mal10.jpg");
		fasefondo = 11;
		break;
	case(11) :
		fondo->setTexture("images/Game2.3/Mal/mal11.jpg");
		fasefondo = 12;
		break;
	case(12) :
		fondo->setTexture("images/Game2.3/Mal/mal12.jpg");
		fasefondo = 13;
		break;
	case(13) :
		fondo->setTexture("images/Game2.3/Mal/mal13.jpg");
		fasefondo = 14;
		break;
	case(14) :
		fondo->setTexture("images/Game2.3/Mal/mal14.jpg");
		fasefondo = 15;
		break;
	case(15) :
		Game23b::goToSelectScene(this);
		break;

	default:
		break;
	}
}
// on "init" you need to initialize your instance
bool Game23b::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Creating Menu

	/*
	auto menuTitle = MenuItemImage::create("images/gameover.png", "images/gameover.png");

	auto playItem = MenuItemImage::create("images/ok.png", "images/ok.png", CC_CALLBACK_1(Game11b::goToMenuScene, this));

	auto menu = Menu::create(menuTitle, playItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	addChild(menu, 1);
	*/

	this->schedule(schedule_selector(Game23b::timer), 1.0);


	/*auto background = Sprite::create("images/game1.2/mal.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);*/

	fondo = Sprite::create("images/game2.3/Mal/mal.jpg");

	fondo->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(fondo, 0);

	this->schedule(schedule_selector(Game23b::animfondo), 0.2);

	return true;
}