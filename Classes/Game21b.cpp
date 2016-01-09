#include "Game21b.h"
#include "GameScene.h"
#include "Game21.h"
#include "MainMenuScene.h"
#include "SelectScene2.h"

USING_NS_CC;
void Game21b::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene2::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game21b::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game21b::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Game21b::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game21b::goToSelectScene(this);
	}
}

void Game21b::animfondo(float dt)
{
	switch (fasefondo)
	{
	case(1) :
		fondo->setTexture("images/Game2.1/Mal/Mal2.jpg");
		fasefondo = 2;
		break;
	case(2) :
		fondo->setTexture("images/Game2.1/Mal/Mal3.jpg");
		fasefondo = 3;
		break;
	case(3) :
		fondo->setTexture("images/Game2.1/Mal/Mal4.jpg");
		fasefondo = 4;
		break;
	case(4) :
		Game21b::goToSelectScene(this);
		break;

	default:
		break;
	}
}
// on "init" you need to initialize your instance
bool Game21b::init()
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

	

	this->schedule(schedule_selector(Game21b::timer), 1.0);


	/*auto background = Sprite::create("images/game2.1/Mal/.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);*/

	fondo = Sprite::create("images/game2.1/Mal/Mal1.jpg");

	fondo->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(fondo, 0);

	this->schedule(schedule_selector(Game21b::animfondo), 0.4);

	return true;
}