#include "Game11a.h"
#include "GameScene.h"
#include "Game11.h"
#include "MainMenuScene.h"

USING_NS_CC;


void Game11a::goToMenuScene(Ref *pSender) {
	auto scene = MainMenuScene::createScene();
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

	auto menuTitle = MenuItemImage::create("images/youwin.png", "images/youwin.png");

	auto playItem = MenuItemImage::create("images/ok.png", "images/ok.png", CC_CALLBACK_1(Game11a::goToMenuScene, this));

	auto menu = Menu::create(menuTitle, playItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 8);
	addChild(menu, 1);


	auto background = Sprite::create("images/hogwarts.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	return true;
}