#include "SelectScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Game11.h"


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

	auto playItem = MenuItemImage::create("images/MainMenuScreen/play.jpg", "images/MainMenuScreen/play_click.jpg", CC_CALLBACK_1(SelectScene::startGame, this));


	auto play = Menu::create(playItem, NULL);

	play->setPosition(Vec2(560, 100));
	
	addChild(play, 1);


	auto background = Sprite::create("images/SelectGame/prehistoria-edad.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	//audio

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/ButtonClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Crash.wav");


	// Inicializando el Sprite del jugador




	//background music

	/*auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (audio->isBackgroundMusicPlaying()==false)
	{
		audio->preloadBackgroundMusic("audio/Music.mp3");
		audio->playBackgroundMusic("audio/Music.mp3", true);
		musicMuted = false;
	}*/
	
	return true;
}