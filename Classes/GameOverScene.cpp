#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void GameOverScene::goToMainMenu(Ref* pSender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(scene);
}

void GameOverScene::retryGameScene(Ref *pSender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(scene);
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
	auto retryItem = MenuItemImage::create("images/GameOverScreen/Retry_Button.png", "images/PauseScreen/Retry_Button(Click).png", CC_CALLBACK_1(GameOverScene::retryGameScene, this));

	auto mainMenuItem = MenuItemImage::create("images/GameOverScreen/Menu_Button.png", "images/PauseScreen/Menu_Button(Click).png", CC_CALLBACK_1(GameOverScene::goToMainMenu, this));


	auto menu = Menu::create(retryItem, mainMenuItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.width / 4);
	addChild(menu, 1);


	auto background = Sprite::create("images/GameOverScreen/Game_Over_Screen_Background.png");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	return true;
}