#include "SelectScene.h"
#include "SelectScene2.h"
#include "MainMenuScene.h"
#include "Game11.h"
#include "Game12.h"
#include "Game13.h"
#include "Global.h"


USING_NS_CC;


Scene* SelectScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SelectScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void SelectScene::startGame(Ref *pSender){
	if (Global::musicPlayed)
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/boton2.mp3");
	auto scene = Game11::createScene();

	Director::getInstance()->replaceScene(TransitionProgressInOut::create(1.0, scene));;
}

void SelectScene::MainMenuScene(Ref *pSender) {
	if (Global::musicPlayed)
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/boton1.mp3");
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));;
}

void SelectScene::goToGame12(Ref *pSender) {
	if (Global::musicPlayed)
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/boton2.mp3");
	auto scene = Game12::createScene();

	Director::getInstance()->replaceScene(TransitionProgressOutIn::create(1.0, scene));;
}

void SelectScene::goToGame13(Ref *pSender) {
	if (Global::musicPlayed)
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/boton2.mp3");
	auto scene = Game13::createScene();

	Director::getInstance()->replaceScene(TransitionProgressInOut::create(1.0, scene));;
}

void SelectScene::goToSelectScene2(Ref *pSender) {
	if (Global::musicPlayed)
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/boton1.mp3");
	auto scene = SelectScene2::createScene();

	Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0, scene));;
}

void SelectScene::checkResults() 
{
	auto res11 = Sprite::create();
	auto res12 = Sprite::create();
	auto res13 = Sprite::create();

	switch (Global::_game11)
	{
	case(1) :
		res11->setTexture("images/SelectGame/tick.png");
		res11->setPosition(Point(230, 550));
		addChild(res11, 2);
		break;
	case(-1) :
		res11->setTexture("images/SelectGame/cross.png");
		res11->setPosition(Point(305, 550));
		addChild(res11, 2);
		break;
	default:
		break;
	}

	switch (Global::_game12)
	{
	case(1) :
		res12->setTexture("images/SelectGame/tick.png");
		res12->setPosition(Point(755, 550));
		addChild(res12, 2);
		break;
	case(-1) :
		res12->setTexture("images/SelectGame/cross.png");
		res12->setPosition(Point(810, 550));
		addChild(res12, 2);
		break;
	default:
		break;
	}

	switch (Global::_game13)
	{
	case(1) :
		res13->setTexture("images/SelectGame/tick.png");
		res13->setPosition(Point(1155, 550));
		addChild(res13, 2);
		break;
	case(-1) :
		res13->setTexture("images/SelectGame/cross.png");
		res13->setPosition(Point(1210, 550));
		addChild(res13, 2);
		break;
	default:
		break;
	}
}

// on "init" you need to initialize your instance
bool SelectScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Creating Menu

	//auto menuTitle = MenuItemImage::create("images/MainMenuScreen/Game_Title.png", "images/MainMenuScreen/Game_Title.png");

	auto backItem = MenuItemImage::create("images/SelectGame/volver.jpg", "images/SelectGame/volver.jpg", CC_CALLBACK_1(SelectScene::MainMenuScene, this));

	auto game11Item = MenuItemImage::create("images/SelectGame/empezar1.jpg", "images/SelectGame/empezar1.jpg", CC_CALLBACK_1(SelectScene::startGame, this));

	auto game12Item = MenuItemImage::create("images/SelectGame/empezar2.jpg", "images/SelectGame/empezar2.jpg", CC_CALLBACK_1(SelectScene::goToGame12, this));

	auto game13Item = MenuItemImage::create("images/SelectGame/empezar3.jpg", "images/SelectGame/empezar3.jpg", CC_CALLBACK_1(SelectScene::goToGame13, this));

	auto selectScene2Item = MenuItemImage::create("images/SelectGame/flcder.png", "images/SelectGame/flcder.png", CC_CALLBACK_1(SelectScene::goToSelectScene2, this));


	auto back = Menu::create(backItem, NULL);
	auto game11 = Menu::create(game11Item, NULL);
	auto game12 = Menu::create(game12Item, NULL);
	auto game13 = Menu::create(game13Item, NULL);
	auto selectScene2 = Menu::create(selectScene2Item, NULL);

	game11->setPosition(Vec2(200, 300));
	game12->setPosition(Vec2(635, 300));
	game13->setPosition(Vec2(1055, 300));

	selectScene2->setPosition(Vec2(1225, 350));

	back->setPosition(Vec2(1150, 650));

	checkResults();

//(1150, 450) coords del siguiente boton

	addChild(back, 3);
	addChild(selectScene2, 3);

	addChild(game13, 2);

	addChild(game12, 2);

	addChild(game11, 1);

	auto background = Sprite::create("images/SelectGame/prehistoria-antigua.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	//audio

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (Global::musicPlayed && Global::phase !=1)
	{
		audio->playBackgroundMusic("audio/juego/levels.mp3", true);
		Global::phase = 1;
		audio->setBackgroundMusicVolume(0.7f);
	}	
	return true;
}