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

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void OptionsScene::reset(Ref *pSender) 
{
	auto scene = Prueba::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));;
}

void OptionsScene::setDifficult(int i) 
{
	__String *text;

	if (i == 0) 
	{
		Global::_max_time = 30;
		dificultad->setString("Dificultad: facil    ");
		return;
	}
	if (i == 1)
	{
		Global::_max_time = 15;
		dificultad->setString("Dificultad: media    ");
		return;
	}
	if (i == 2)
	{
		Global::_max_time = 10;
		dificultad->setString("Dificultad: dificil  ");
		return;
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


	auto background = Sprite::create("images/opcionesfondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);


	auto backItem = MenuItemImage::create("images/SelectGame/back.png", "images/SelectGame/back_click.png", CC_CALLBACK_1(OptionsScene::goToMainMenu, this));
	auto resetItem = MenuItemImage::create("images/Testing/botones/reset.png", "images/Testing/botones/reset.png", CC_CALLBACK_1(OptionsScene::reset, this));


	auto back = Menu::create(backItem, NULL);
	auto reset = Menu::create(resetItem, NULL);

	back->setPositionX(120); back->setPositionY(406);
	reset->setPosition(Vec2(680, 140));


	addChild(back, 1);
	addChild(reset, 10);

	__String *text = __String::createWithFormat("Dificultad: media");
	dificultad = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 48);
	dificultad->setTextColor(Color4B::BLACK);
	dificultad->setPosition(Vec2(680, 630));
	addChild(dificultad, 2);


	text = __String::createWithFormat("Nueva Partida");
	newGame = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 48);
	newGame->setTextColor(Color4B::BLACK);
	newGame->setPosition(Vec2(680, 255));

	addChild(newGame, 2);


	this->easy = Sprite::create("images/Testing/botones/facil.png");
	this->easy->setPosition(500, 515);
	this->addChild(easy, 10);

	this->medium = Sprite::create("images/Testing/botones/medio.png");
	this->medium->setPosition(680, 515);
	this->addChild(medium, 10);

	this->hard = Sprite::create("images/Testing/botones/dificil.png");
	this->hard->setPosition(860, 515);
	this->addChild(hard, 10);

	auto event_listener = EventListenerTouchAllAtOnce::create();


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
	};

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