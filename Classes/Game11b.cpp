#include "Game11b.h"
#include "GameScene.h"
#include "Game11.h"
#include "MainMenuScene.h"

USING_NS_CC;
void Game11b::goToMenuScene(Ref *pSender) {
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->pushScene(scene);
}

Scene* Game11b::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game11b::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Game11b::timer(float dt)
{
	_time++;

	if (_time == 4) {
		Game11b::goToMenuScene(this);
	}
}
// on "init" you need to initialize your instance
bool Game11b::init()
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

	auto image = Sprite::create("images/game1.1/mal.png");

	image->setPosition(Point((visibleSize.width / 2.5), (visibleSize.height / 3.2)));
	image->setScale(0.6f);


	addChild(image, 1);

	this->schedule(schedule_selector(Game11b::timer), 1.0);


	auto background = Sprite::create("images/game1.1/fondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	return true;
}