#include "SelectScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Game11.h"
#include "Game12.h"


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
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = Game11::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void SelectScene::goToGame12(Ref *pSender) {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = Game12::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void SelectScene::pauseMusic(){
	if (musicMuted)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
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

	auto playItem = MenuItemImage::create("images/SelectGame/Start.png", "images/SelectGame/Start_click.png", CC_CALLBACK_1(SelectScene::startGame, this));

	auto game12Item = MenuItemImage::create("images/SelectGame/Start.png", "images/SelectGame/Start_click.png", CC_CALLBACK_1(SelectScene::goToGame12, this));


	auto play = Menu::create(playItem, NULL);
	auto game12 = Menu::create(game12Item, NULL);

	play->setPosition(Vec2(300, 450));
	game12->setPosition(Vec2(725, 450));
//(1150, 450) coords del siguiente boton

	addChild(game12, 2);

	addChild(play, 1);


	auto background = Sprite::create("images/SelectGame/prehistoria-edad.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	//audio

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/ButtonClick.wav");
	return true;
}