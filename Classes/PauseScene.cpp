#include "PauseScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"


USING_NS_CC;

Scene* PauseScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PauseScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void PauseScene::resumeGameScene(Ref *pSender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	Director::getInstance()->popScene();
}

void PauseScene::goToMainMenu(Ref *pSender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);

}

void PauseScene::retryGameScene(Ref *pSender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = GameScene::createScene();

	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

// on "init" you need to initialize your instance
bool PauseScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
	auto resumeItem = MenuItemImage::create("images/PauseScreen/Resume_Button.png", "images/PauseScreen/Resume_Button(Click).png", CC_CALLBACK_1(PauseScene::resumeGameScene, this));

	auto replayItem = MenuItemImage::create("images/PauseScreen/Retry_Button.png", "images/PauseScreen/Retry_Button(Click).png", CC_CALLBACK_1(PauseScene::retryGameScene, this));

	auto mainMenuItem = MenuItemImage::create("images/PauseScreen/Menu_Button.png", "images/PauseScreen/Menu_Button(Click).png", CC_CALLBACK_1(PauseScene::goToMainMenu, this));


	auto menu = Menu::create(resumeItem, replayItem, mainMenuItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.width / 6);
	addChild(menu, 1);


	auto background = Sprite::create("images/PauseScreen/Pause_Background.png");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	return true;
}