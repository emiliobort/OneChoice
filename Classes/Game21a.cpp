#include "Game21a.h"
#include "GameScene.h"
#include "Game21.h"
#include "MainMenuScene.h"
#include "SelectScene2.h"

USING_NS_CC;


void Game21a::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene2::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game21a::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Game21a::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void Game21a::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game21a::goToSelectScene(this);
	}
}

// on "init" you need to initialize your instance
bool Game21a::init()
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

	


	this->schedule(schedule_selector(Game21a::timer), 1.0);

	auto background = Sprite::create("images/game2.1/Bien/Bien.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	auto corona = Sprite::create("images/game2.1/Bien/corona_bien.png");
	corona->setPosition(Vec2(380,(visibleSize.height+100)));

	auto *move = (Action *)MoveTo::create(3.0f, Vec2(380, (visibleSize.height / 2)+120));
	corona->runAction(move);

	addChild(corona, 0);
	return true;
}