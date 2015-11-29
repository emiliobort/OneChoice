#include "OptionsScene.h"
#include "MainMenuScene.h"
#include "Global.h"


USING_NS_CC;


Scene* OptionsScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = OptionsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


void OptionsScene::goToMainMenu(Ref *pSender) {
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}


// on "init" you need to initialize your instance
bool OptionsScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Creating Menu


	auto background = Sprite::create("images/enConstruccion.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);


	auto backItem = MenuItemImage::create("images/SelectGame/back.png", "images/SelectGame/back_click.png", CC_CALLBACK_1(OptionsScene::goToMainMenu, this));

	auto back = Menu::create(backItem, NULL);

	back->setPosition(Vec2(300, 450));
	addChild(back, 1);

	__String *text = __String::createWithFormat("Game11 %d   ", Global::_game11);
	_game1_1 = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 24);
	_game1_1->setTextColor(Color4B::BLACK);
	_game1_1->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 30));

	addChild(_game1_1, 2);

	text = __String::createWithFormat("Game12 %d   ", Global::_game12);
	_game1_2 = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 24);
	_game1_2->setTextColor(Color4B::BLACK);
	_game1_2->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 60));

	addChild(_game1_2, 2);

	text = __String::createWithFormat("Game13 %d   ", Global::_game13);
	_game1_3 = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 24);
	_game1_3->setTextColor(Color4B::BLACK);
	_game1_3->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 90));

	addChild(_game1_3, 2);

	text = __String::createWithFormat("Game21 %d   ", Global::_game21);
	_game2_1 = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 24);
	_game2_1->setTextColor(Color4B::BLACK);
	_game2_1->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 120));

	addChild(_game2_1, 2);

	text = __String::createWithFormat("Game22 %d   ", Global::_game22);
	_game2_2 = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 24);
	_game2_2->setTextColor(Color4B::BLACK);
	_game2_2->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 150));

	addChild(_game2_2, 2);

	text = __String::createWithFormat("Game23 %d   ", Global::_game23);
	_game2_3 = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 24);
	_game2_3->setTextColor(Color4B::BLACK);
	_game2_3->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 180));

	addChild(_game2_3, 2);

	return true;
}