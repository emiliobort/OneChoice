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

	auto image = Sprite::create("images/game1.1/bien.png");

	image->setPosition(Point((visibleSize.width / 2.5),(visibleSize.height / 3.2)));
	image->setScale(0.6f);

	addChild(image, 1);


	this->schedule(schedule_selector(Game13a::timer), 1.0);

	auto background = Sprite::create("images/game1.1/fondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	return true;
}