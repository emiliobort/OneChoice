#include "SelectScene2.h"
#include "SelectScene.h"
#include "MainMenuScene.h"
#include "Game21.h"
//#include "Game22.h"
//#include "Game23.h"
#include "Global.h"

USING_NS_CC;


Scene* SelectScene2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SelectScene2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void SelectScene2::startGame(Ref *pSender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = Game21::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void SelectScene2::MainMenuScene(Ref *pSender) {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void SelectScene2::goToSelectScene(Ref *pSender) {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = SelectScene::createScene();

	Director::getInstance()->replaceScene(TransitionSlideInL::create(1.0, scene));;
}

/*
void SelectScene2::goToGame12(Ref *pSender) {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = Game12::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void SelectScene2::goToGame13(Ref *pSender) {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = Game13::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}
*/

void SelectScene2::checkResults()
{
	auto res21 = Sprite::create();
	auto res22 = Sprite::create();
	auto res23 = Sprite::create();

	switch (Global::_game21)
	{
	case(1) :
		res21->setTexture("images/SelectGame/tick.png");
		res21->setPosition(Point(330, 550));
		res21->setScale(0.15f);
		addChild(res21, 2);
		break;
	case(-1) :
		res21->setTexture("images/SelectGame/cross.png");
		res21->setPosition(Point(385, 550));
		res21->setScale(0.15f);
		addChild(res21, 2);
		break;
	default:
		break;
	}

	switch (Global::_game12)
	{
	case(1) :
		res22->setTexture("images/SelectGame/tick.png");
		res22->setPosition(Point(755, 550));
		res22->setScale(0.15f);
		addChild(res22, 2);
		break;
	case(-1) :
		res22->setTexture("images/SelectGame/cross.png");
		res22->setPosition(Point(810, 550));
		res22->setScale(0.15f);
		addChild(res22, 2);
		break;
	default:
		break;
	}

	switch (Global::_game13)
	{
	case(1) :
		res23->setTexture("images/SelectGame/tick.png");
		res23->setPosition(Point(1155, 550));
		res23->setScale(0.15f);
		addChild(res23, 2);
		break;
	case(-1) :
		res23->setTexture("images/SelectGame/cross.png");
		res23->setPosition(Point(1210, 550));
		res23->setScale(0.15f);
		addChild(res23, 2);
		break;
	default:
		break;
	}
}

// on "init" you need to initialize your instance
bool SelectScene2::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Creating Menu


	auto backItem = MenuItemImage::create("images/flechas/inicio.png", "images/flechas/inicio.png", CC_CALLBACK_1(SelectScene2::MainMenuScene, this));

	auto game21Item = MenuItemImage::create("images/SelectGame/Start.png", "images/SelectGame/Start_click.png", CC_CALLBACK_1(SelectScene2::startGame, this));

	//auto game22Item = MenuItemImage::create("images/SelectGame/Start.png", "images/SelectGame/Start_click.png", CC_CALLBACK_1(SelectScene2::goToGame12, this));

	//auto game23Item = MenuItemImage::create("images/SelectGame/Start.png", "images/SelectGame/Start_click.png", CC_CALLBACK_1(SelectScene2::goToGame13, this));

	auto selectSceneItem = MenuItemImage::create("images/flechas/volver.png", "images/flechas/volver.png", CC_CALLBACK_1(SelectScene2::goToSelectScene, this));

	auto back = Menu::create(backItem, NULL);
	auto game21 = Menu::create(game21Item, NULL);
	//auto game22 = Menu::create(game22Item, NULL);
	//auto game23 = Menu::create(game23Item, NULL);
	auto selectScene = Menu::create(selectSceneItem, NULL);

	game21->setPosition(Vec2(300, 450));
	//game22->setPosition(Vec2(725, 450));
	//game23->setPosition(Vec2(1125, 450));
	
	back->setPosition(Vec2(0, 0));
	back->setScale(0.5f);
	back->setPosition(Vec2(1150/1.25, 650/1.3));
	selectScene->setPosition(Vec2(50, 350));

	checkResults();


//(1150, 450) coords del siguiente boton

	addChild(back, 3);

	addChild(selectScene, 3);

	//addChild(game23, 2);

	//addChild(game22, 2);

	addChild(game21, 1);


	auto background = Sprite::create("images/SelectGame/media-moderna.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	return true;
}