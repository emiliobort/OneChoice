#include "Prueba.h"
#include "Global.h"
#include "MainMenuScene.h"

//Con definimos las variables globales para luego inicializarlas al valor que queramos.

int Global::_game11;
int Global::_game12;
int Global::_game13;
int Global::_game21;
int Global::_game22;
int Global::_game23;
int Global::_max_time;
bool Global::musicPlayed;

USING_NS_CC;

Scene* Prueba::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Prueba::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Prueba::startGame(Ref *pSender) {
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));;
}

void Prueba::timer(float dt) {
	_time++;

	if (_time == 4) {
		Prueba::startGame(this);
	}
}

bool Prueba::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//Inicializamos las variables globales de los juegos.

	Global::_game11 = 0;
	Global::_game12 = 0;
	Global::_game13 = 0;
	Global::_game21 = 0;
	Global::_game22 = 0;
	Global::_game23 = 0;
	Global::_max_time = 25;
	Global::musicPlayed = true;


	Size visibleSize = Director::getInstance()->getVisibleSize();



	auto background = Sprite::create("images/CompanyScene/empresa.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);


	this->schedule(schedule_selector(Prueba::timer), 1.0);

	return true;
}
