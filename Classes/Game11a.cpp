#include "Game11a.h"
#include "GameScene.h"
#include "Game11.h"
#include "MainMenuScene.h"
#include "SelectScene.h"

USING_NS_CC;


void Game11a::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game11a::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Game11a::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void Game11a::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game11a::goToSelectScene(this);
	}
}

void Game11a::animfondo(float dt)
{
	switch (fasefondo)
	{
	case(1) :
		fondo->setTexture("images/Game1.1/Bien/bien2.jpg");
		fasefondo = 2;
		break;
	case(2) :
		fondo->setTexture("images/Game1.1/Bien/bien3.jpg");
		fasefondo = 3;
		break;
	case(3) :
		fondo->setTexture("images/Game1.1/Bien/bien4.jpg");
		fasefondo = 4;
		break;
	case(4) :
		fondo->setTexture("images/Game1.1/Bien/bien5.jpg");
		fasefondo = 5;
		break;
	case(5) :
		Game11a::goToSelectScene(this);
		break;

	default:
		break;
	}
}

// on "init" you need to initialize your instance
bool Game11a::init()
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

	/*	//solo mueve al personaje
	auto image = Sprite::create("images/game1.1/Bien/bien1.png");

	image->setPosition(Point((visibleSize.width / 2.5),(visibleSize.height / 3.2)));
	image->setScale(0.6f);


	auto *move = (Action *)MoveTo::create(4.0f, Vec2(image->getPositionX()+ visibleSize.width, visibleSize.height / 3.2));
	image->runAction(move);

	addChild(image, 1);


	this->schedule(schedule_selector(Game11a::timer), 1.0);

	auto background = Sprite::create("images/game1.1/fondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);*/

	//cambia fondo

	fondo = Sprite::create("images/game1.1/Bien/bien1.jpg");

	fondo->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(fondo, 0); 

	this->schedule(schedule_selector(Game11a::animfondo), 0.4);

	return true;


}