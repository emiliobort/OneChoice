#include "Game12a.h"
#include "GameScene.h"
#include "Game12.h"
#include "MainMenuScene.h"
#include "SelectScene.h"

USING_NS_CC;


void Game12a::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game12a::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Game12a::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void Game12a::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game12a::goToSelectScene(this);
	}
}

// on "init" you need to initialize your instance
bool Game12a::init()
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


	this->schedule(schedule_selector(Game12a::timer), 1.0);

	auto background = Sprite::create("images/game1.2/bien.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	return true;


}