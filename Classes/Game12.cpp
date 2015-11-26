#include "Game12.h"

#include "Global.h"

USING_NS_CC;

/*void Game12::goToOptionA(Ref *pSender) {
	auto scene = Game12a::createScene();
	Director::getInstance()->pushScene(scene);
}

void Game12::goToOptionB(Ref *pSender) {
	auto scene = Game12b::createScene();
	Director::getInstance()->replaceScene(scene);
}*/

Scene* Game12::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game12::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool Game12::init()
{


	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Inicializando el Fondo

	auto background = Sprite::create("images/Game1.2/fondo2.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	// Inicializando el Sprite del jugador

	_piece1 = Sprite::create("images/Game1.2/piece1.png");

	_piece1->setPosition(Point(visibleSize.width / 4, visibleSize.height - _piece1->getContentSize().height / 2));

	addChild(_piece1, 1);

	return true;
}
