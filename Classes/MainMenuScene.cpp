#include "MainMenuScene.h"
#include "GameScene.h"
#include "Game11.h"

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

void MainMenuScene::startGame(Ref *pSender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = Game11::createScene();

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

	auto menuTitle = MenuItemImage::create("images/MainMenuScreen/Game_Title.png", "images/MainMenuScreen/Game_Title.png");

	auto playItem = MenuItemImage::create("images/MainMenuScreen/Play_Button.png", "images/MainMenuScreen/Play_Button(Click).png", CC_CALLBACK_1(MainMenuScene::startGame, this));

	auto menu = Menu::create(menuTitle, playItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	addChild(menu, 1);


	auto background = Sprite::create("images/MainMenuScreen/Background.png");

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