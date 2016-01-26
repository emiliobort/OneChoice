#include "OptionsScene.h"
#include "MainMenuScene.h"
#include "Global.h"
#include "Prueba.h"


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
	if (Global::musicPlayed)
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/boton1.mp3");
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionShrinkGrow::create(1.0, scene));;
}

void OptionsScene::reset(Ref *pSender) 
{
	auto scene = Prueba::createScene();
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));;
}

void OptionsScene::setDifficult(int i) 
{
	__String *text;

	if (i == 0) 
	{
		Global::_max_time = 30;
		easy->setOpacity(255);
		medium->setOpacity(125);
		hard->setOpacity(125);
		return;
	}
	if (i == 1)
	{
		Global::_max_time = 15;
		medium->setOpacity(255);
		easy->setOpacity(125);
		hard->setOpacity(125);
		return;
	}
	if (i == 2)
	{
		Global::_max_time = 10;
		hard->setOpacity(255);
		medium->setOpacity(125);
		easy->setOpacity(125);
		return;
	}
}

void OptionsScene::musicOnOff() {
	if (Global::musicPlayed)
	{
		this->music->setTexture("images/OptionsScreen/off.jpg");
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		Global::musicPlayed = false;
	}
	else
	{
		this->music->setTexture("images/OptionsScreen/on.jpg");
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		Global::musicPlayed = true;
	}

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

	auto background = Sprite::create("images/OptionsScreen/fondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);


	auto backItem = MenuItemImage::create("images/OptionsScreen/volver.jpg", "images/OptionsScreen/volver.jpg", CC_CALLBACK_1(OptionsScene::goToMainMenu, this));
	auto resetItem = MenuItemImage::create("images/OptionsScreen/reset.jpg", "images/OptionsScreen/reset.jpg", CC_CALLBACK_1(OptionsScene::reset, this));


	auto back = Menu::create(backItem, NULL);
	auto reset = Menu::create(resetItem, NULL);

	back->setPositionX(1147); back->setPositionY(654);
	reset->setPosition(Vec2(197, 85));


	addChild(back, 1);
	addChild(reset, 10);

	this->easy = Sprite::create("images/OptionsScreen/facil.jpg");
	this->easy->setPosition(197, 418);
	this->addChild(easy, 10);

	this->medium = Sprite::create("images/OptionsScreen/media.jpg");
	this->medium->setPosition(411, 418);
	this->addChild(medium, 10);

	this->hard = Sprite::create("images/OptionsScreen/dificil.jpg");
	this->hard->setPosition(625, 418);
	this->addChild(hard, 10);

	this->music = Sprite::create("images/OptionsScreen/on.jpg");
	this->music->setPosition(304, 260);
	this->addChild(music, 10);

	switch (Global::_max_time)
	{
	case 30:
		hard->setOpacity(125);
		medium->setOpacity(125);
		easy->setOpacity(255);
		break;
	case 15:
		hard->setOpacity(125);
		medium->setOpacity(255);
		easy->setOpacity(125);
		break;
	case 10:
		hard->setOpacity(255);
		medium->setOpacity(125);
		easy->setOpacity(125);
		break;
	default:
		break;
	}

	auto event_listener = EventListenerTouchAllAtOnce::create();

	if (!Global::musicPlayed)
		this->music->setTexture("images/OptionsScreen/off.jpg");
	else
		this->music->setTexture("images/OptionsScreen/on.jpg");


	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distance;
		distance = this->easy->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			setDifficult(0);
			return;
		}
		distance = this->medium->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			setDifficult(1);
			return;
		}
		distance = this->hard->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			setDifficult(2);
			return;
		}
		distance = this->music->getPosition().getDistance(touch->getLocation());
		if (distance < 40) {
			musicOnOff();
			return;
		}
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, easy);


	return true;
}