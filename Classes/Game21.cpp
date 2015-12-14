#include "Game21.h"
#include "Game21a.h"
#include "Game21b.h"
#include "Global.h"

USING_NS_CC;

//funciones
/*
INIT
Se encargará de cargar las imagenes por primera vez y de inicializar las variables necesarias (en este caso el contador)

CONTADOR
Actulizará el contador si se pulsa la tecla correcta o saldrá del juego si se pulsa la incorrecta
Actualizará los sprites del muñeco y la rueda

PAUSA-INFO
Cargará una pantalla que pausará el juego y mostrará la información del nivel (historia) al comienzo de este

FIN
Volverá a la pantalla anterior (SELECTLEVEL1) actualizando la variable global en función del resultado obtenido

*/


void Game21::goToOptionA(Ref *pSender) {
	auto scene = Game21a::createScene();
	Director::getInstance()->pushScene(scene);
}

void Game21::goToOptionB(Ref *pSender) {
	auto scene = Game21b::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game21::contador()
{

	_score ++;

	__String *text = __String::createWithFormat("Score %d    ", _score);
	_labelScore->setString(text->getCString());

	if (_score == 10)
	{
		_playerSprite->setTexture("images/Game2.1/arturo01.png ");
		_aux = 1;
	}

	if (_score == 20)
	{
		_playerSprite->setTexture("images/Game2.1/arturo02.png");
		_aux = 2;
	}
	if (_score == 30)
	{
		_playerSprite->setTexture("images/Game2.1/arturo03.png");
		_aux = 2;
	}

	if (_score == 40)
	{

		_playerSprite->setTexture("images/Game2.1/arturo04.png");
		_aux = 3;
	}

	if (_score == 60)
	{

		_playerSprite->setTexture("images/Game2.1/arturo05.png");
		_aux = 3;
	}

	

	if (_score == 80)
	{

		_playerSprite->setTexture("images/Game2.1/arturo06.png");
		_aux = 3;
	}

	if (_score == 90)
	{

		_playerSprite->setTexture("images/Game2.1/arturo07.png");
		_aux = 3;
	}


	if (_score >89 && _time == 15) //para comprobar que funciona
	{

		Global::_game21 = 1;
		Game21::goToOptionA(this);
	}


}

Scene* Game21::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game21::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Game21::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;
	if (_pressedKey == EventKeyboard::KeyCode::KEY_SPACE)
	{
		Game21::contador();
	}
}



void Game21::timer(float dt) {
	_time++;

	String *tiempo = String::createWithFormat("%d", 15 - _time);
	_timer->setString(tiempo->getCString());

	if (_time == 16)
	{
		goToOptionB(this);
	}
}

bool Game21::init()
{


	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Inicializando el Fondo

	auto background = Sprite::create("images/Game2.1/fondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	
	
	//inicializando los sprites de texto de kao  
	_playerSprite = Sprite::create("images/Game2.1/texto_arturo1.png");

	_playerSprite->setPosition(Point(visibleSize.width / 1.5, _playerSprite->getContentSize().height / 1.1));
	_playerSprite->setScale(0.4f);

	addChild(_playerSprite, 1);
	
	//inicializando los sprites de arturo 

	_playerSprite = Sprite::create("images/Game2.1/arturo00.png");

	_playerSprite->setPosition(Point(visibleSize.width / 2, _playerSprite->getContentSize().height / 2));
	_playerSprite->setScale(0.6f);

	addChild(_playerSprite, 1);

	// Configuramos la funcion de las teclas
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game21::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	//Coloca el Label donde se encuentra la puntuacion (numero de clicks ahora mismo)
	__String *text = __String::createWithFormat("Score %d    ", _score);
	_labelScore = Label::createWithTTF(text->getCString(), "fonts/trebuc.ttf", 24);
	_labelScore->setPosition(Vec2(visibleSize.width - 190, visibleSize.height - 30));

	String *tiempo = String::createWithFormat("");
	_timer = Label::createWithTTF(tiempo->getCString(), "fonts/trebuc.ttf", 48);
	_timer->setPosition(Vec2(visibleSize.width - 90, visibleSize.height - 50));
	_timer->setTextColor(Color4B::WHITE);
	_timer->setScale(1.3);

	//Timer

	addChild(_labelScore, 1);
	addChild(_timer, 1);
	this->schedule(schedule_selector(Game21::timer), 1.0);

	return true;
}

