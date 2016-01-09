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
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
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

	/*
	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();
		float distance;

		distance = this->easy->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			piece_selected = 1;
			return;
		}

		distance = this->medium->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			piece_selected = 2;
			return;
		}

		distance = this->hard->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			piece_selected = 3;
			return;
		}

		distance = this->music->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			piece_selected = 4;
			return;
		}

		distance = this->dificultad->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			piece_selected = 5;
			return;
		}

	};

	event_listener->onTouchesEnded = [=](const std::vector<Touch*>& pTouches, Event* event) {


		switch (piece_selected)
		{
		case 1:
			CCLOG("%f %f", easy->getPositionX(), easy->getPositionY());
			
			break;

		case 2:
			CCLOG("%f %f", medium->getPositionX(), medium->getPositionY());
			
			break;
		case 3:
			CCLOG("%f %f", hard->getPositionX(), hard->getPositionY());
			
			break;
		case 4:
			CCLOG("%f %f", music->getPositionX(), music->getPositionY());
			
			break;
		case 5:
			CCLOG("%f %f", dificultad->getPositionX(), dificultad->getPositionY());
			
			break;
		default:
			break;
		}

		piece_selected = 0;

	};

	event_listener->onTouchesMoved = [=](const std::vector<Touch*>& pTouches, Event* event) {

		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		auto move_action = MoveTo::create(0.001f, openGl_location);

		if (piece_selected == 1) {
			easy->setPosition(touch->getLocation());
		}
		if (piece_selected == 2) {
			medium->setPosition(touch->getLocation());
		}
		if (piece_selected == 3) {
			hard->setPosition(touch->getLocation());
		}
		if (piece_selected == 4) {
			music->setPosition(touch->getLocation());
		}
		if (piece_selected == 5) {
			dificultad->setPosition(touch->getLocation());
		}
	};

	*/

	/*__String *text = __String::createWithFormat("Game11 %d   ", Global::_game11);
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

	addChild(_game2_3, 2);*/

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, easy);


	return true;
}