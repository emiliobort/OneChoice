#include "Game13a.h"
#include "GameScene.h"
#include "Game13.h"
#include "MainMenuScene.h"
#include "SelectScene.h"

USING_NS_CC;


void Game13a::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game13a::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Game13a::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}



void Game13a::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game13a::goToSelectScene(this);
	}
}

void Game13a::animfondo(float dt)
{
	switch (fasefondo)
	{
	case(1) :
		cesar->setTexture("images/Game1.3/Bien/bien2.png");
		fasefondo = 2;
		break;
	case(2) :
		cesar->setTexture("images/Game1.3/Bien/bien3.png");
		fasefondo = 3;
		break;
	case(3) :
		cesar->setTexture("images/Game1.3/Bien/bien4.png");
		fasefondo = 4;
		break;
	case(4) :
		cesar->setTexture("images/Game1.3/Bien/bien1.png");
		fasefondo = 5;
		break;
	case(5) :
		cesar->setTexture("images/Game1.3/Bien/bien2.png");
		fasefondo = 6;
		break;
	case(6) :
		cesar->setTexture("images/Game1.3/Bien/bien3.png");
		fasefondo = 7;
		break;
	case(7) :
		cesar->setTexture("images/Game1.3/Bien/bien4.png");
		fasefondo = 8;
		break;
	case(8) :
		Game13a::goToSelectScene(this);
		break;

	default:
		break;
	}
}

// on "init" you need to initialize your instance
bool Game13a::init()
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
	auto menuTitle = MenuItemImage::create("images/youwin.png", "images/youwin.png");

	auto playItem = MenuItemImage::create("images/ok.png", "images/ok.png", CC_CALLBACK_1(Game11a::goToMenuScene, this));

	auto menu = Menu::create(menuTitle, playItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 8);
	addChild(menu, 1);
	*/

	/*auto image = Sprite::create("images/game1.1/bien.png");

	image->setPosition(Point((visibleSize.width / 2.5),(visibleSize.height / 3.2)));
	image->setScale(0.6f);

	addChild(image, 1);


	this->schedule(schedule_selector(Game13a::timer), 1.0);

	auto background = Sprite::create("images/game1.1/fondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);*/

	fondo = Sprite::create("images/game1.3/Bien/Bien.jpg");

	fondo->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(fondo, 0);

	cesar = Sprite::create("images/game1.3/Bien/bien1.png");

	cesar->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));
	cesar->setScale(0.9f);

	addChild(cesar, 0);

	this->schedule(schedule_selector(Game13a::animfondo), 0.4);

	return true;
}