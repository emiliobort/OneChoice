#include "Game13b.h"
#include "GameScene.h"
#include "Game13.h"
#include "MainMenuScene.h"
#include "SelectScene.h"

USING_NS_CC;
void Game13b::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game13b::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game13b::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Game13b::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game13b::goToSelectScene(this);
	}
}

void Game13b::animfondo(float dt)
{
	switch (fasefondo)
	{
	case(1) :
		cesar->setTexture("images/Game1.3/Mal/mal2.png");
		fasefondo = 2;
		break;
	case(2) :
		cesar->setTexture("images/Game1.3/Mal/mal3.png");
		fasefondo = 3;
		break;
	case(3) :
		cesar->setTexture("images/Game1.3/Mal/mal4.png");
		fasefondo = 4;
		break;
	case(4) :
		cesar->setTexture("images/Game1.3/Mal/mal1.png");
		fasefondo = 5;
		break;
	case(5) :
		cesar->setTexture("images/Game1.3/Mal/mal2.png");
		fasefondo = 6;
		break;
	case(6) :
		cesar->setTexture("images/Game1.3/Mal/mal3.png");
		fasefondo = 7;
		break;
	case(7) :
		cesar->setTexture("images/Game1.3/Mal/mal4.png");
		fasefondo = 8;
		break;
	case(8) :
		Game13b::goToSelectScene(this);
		break;

	default:
		break;
	}
}

// on "init" you need to initialize your instance
bool Game13b::init()
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

	/*auto image = Sprite::create("images/game1.1/mal.png");

	image->setPosition(Point((visibleSize.width / 2.5), (visibleSize.height / 3.2)));
	image->setScale(0.6f);


	addChild(image, 1);

	this->schedule(schedule_selector(Game13b::timer), 1.0);


	auto background = Sprite::create("images/game1.1/fondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);*/

	fondo = Sprite::create("images/game1.3/Mal/Mal.jpg");

	fondo->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(fondo, 0);

	cesar = Sprite::create("images/game1.3/Mal/mal1.png");

	cesar->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));
	cesar->setScale(0.9f);

	addChild(cesar, 0);

	this->schedule(schedule_selector(Game13b::animfondo), 0.4);

	return true;
}