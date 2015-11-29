#include "MainMenuScene.h"
#include "SelectScene.h"
#include "OptionsScene.h"

USING_NS_CC;


Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


void MainMenuScene::selectGame(Ref *pSender) {
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = SelectScene::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void MainMenuScene::optionScene(Ref *pSender) {
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = OptionsScene::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}


void MainMenuScene::pauseMusic(){
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
bool MainMenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Creating Menu

	auto playItem = MenuItemImage::create("images/MainMenuScreen/play.jpg", "images/MainMenuScreen/play_click.jpg", CC_CALLBACK_1(MainMenuScene::selectGame, this));
	auto optionItem = MenuItemImage::create("images/MainMenuScreen/options.jpg", "images/MainMenuScreen/options_click.jpg", CC_CALLBACK_1(MainMenuScene::optionScene, this));


	auto play = Menu::create(playItem, NULL);
	auto option = Menu::create(optionItem, NULL);

	play->setPosition(Vec2(560, 100));
	option->setPosition(Vec2(780, 100));
	
	addChild(play, 1);
	addChild(option, 1);


	auto background = Sprite::create("images/MainMenuScreen/Background.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	//audio

	/*	
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/ButtonClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Crash.wav");
	*/
	return true;
}