#include "Game22a.h"
#include "GameScene.h"
#include "Game22.h"
#include "MainMenuScene.h"
#include "SelectScene2.h"

USING_NS_CC;


void Game22a::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene2::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game22a::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Game22a::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void Game22a::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game22a::goToSelectScene(this);
	}
}

void Game22a::animfondo(float dt)
{
	switch (fasefondo)
	{
	case(1) :
		fondo->setTexture("images/Game2.2/Bien/bien2.jpg");
		fasefondo = 2;
		break;
	case(2) :
		fondo->setTexture("images/Game2.2/Bien/bien3.jpg");
		fasefondo = 3;
		break;
	case(3) :
		fondo->setTexture("images/Game2.2/Bien/bien4.jpg");
		fasefondo = 4;
		break;
	case(4) :
		Game22a::goToSelectScene(this);
		break;

	default:
		break;
	}
}

// on "init" you need to initialize your instance
bool Game22a::init()
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


	this->schedule(schedule_selector(Game22a::timer), 1.0);

	/*auto background = Sprite::create("images/game1.2/bien.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);*/

	fondo = Sprite::create("images/game2.2/Bien/bien.jpg");

	fondo->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(fondo, 0);

	this->schedule(schedule_selector(Game22a::animfondo), 0.4);

	return true;


}