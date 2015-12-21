#include "Prueba.h"
#include "MainMenuScene.h"
#include "Kao.h"
#include "SelectScene.h"

//Con definimos las variables globales para luego inicializarlas al valor que queramos.


USING_NS_CC;

Scene* Kao::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Kao::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Kao::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene::createScene();
	Director::getInstance()->pushScene(scene);
	Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(1.0, scene));
}

void Kao::contador()
{

	_score++;
	Size visibleSize = Director::getInstance()->getVisibleSize();

	

	if (_score == 1)
	{
		auto background = Sprite::create("images/Kao/kao2.jpg");

		background->setPosition(Point((visibleSize.width / 2),
			(visibleSize.height / 2)));

		addChild(background, 0);
		
	}

	if (_score == 2)
	{
		auto background = Sprite::create("images/Kao/kao3.jpg");

		background->setPosition(Point((visibleSize.width / 2),
			(visibleSize.height / 2)));

		addChild(background, 0);
		
	}
	if (_score == 3)
	{

		auto background = Sprite::create("images/Kao/kao4.jpg");

		background->setPosition(Point((visibleSize.width / 2),
			(visibleSize.height / 2)));

		addChild(background, 0);
	}

	if (_score == 4) 
	{

		Kao::goToSelectScene(this);
	}


}

void Kao::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;
	if (_pressedKey == EventKeyboard::KeyCode::KEY_C)
	{
		Kao::contador();
	}
}




bool Kao::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//Inicializamos las variables globales de los juegos.

	



	Size visibleSize = Director::getInstance()->getVisibleSize();

	
	// Configuramos la funcion de las teclas
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Kao::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//Imagen Kao

	auto background = Sprite::create("images/Kao/kao1.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);



	

	return true;
}
