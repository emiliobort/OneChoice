#include "Game21.h"
#include "Game21a.h"
#include "Game21b.h"
#include "Global.h"

USING_NS_CC;

//funciones
/*
INIT
Se encargar� de cargar las imagenes por primera vez y de inicializar las variables necesarias (en este caso el contador)

CONTADOR
Actulizar� el contador si se pulsa la tecla correcta o saldr� del juego si se pulsa la incorrecta
Actualizar� los sprites del mu�eco y la rueda

PAUSA-INFO
Cargar� una pantalla que pausar� el juego y mostrar� la informaci�n del nivel (historia) al comienzo de este

FIN
Volver� a la pantalla anterior (SELECTLEVEL1) actualizando la variable global en funci�n del resultado obtenido

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
		_playerSprite->setTexture("images/Game2.1/2.png");
		_aux = 1;
	}

	if (_score == 20)
	{
		_playerSprite->setTexture("images/Game2.1/3.png");
		_aux = 2;
	}
	if (_score == 30)
	{

		_playerSprite->setTexture("images/Game2.1/4.png");
		_aux = 3;
	}

	if (_score == 40)
	{

		_playerSprite->setTexture("images/Game2.1/5.png");
		_aux = 3;
	}

	if (_score == 50)
	{

		_playerSprite->setTexture("images/Game2.1/6.png");
		_aux = 3;
	}

	if (_score == 60)
	{

		_playerSprite->setTexture("images/Game2.1/7.png");
		_aux = 3;
	}

	if (_score == 70)
	{

		_playerSprite->setTexture("images/Game2.1/8.png");
		_aux = 3;
	}

	if (_score == 80)
	{

		_playerSprite->setTexture("images/Game2.1/9.png");
		_aux = 3;
	}

	if (_score == 90) //para comprobar que funciona
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

	String *tiempo = String::createWithFormat("time %d    ", _time);
	_timer->setString(tiempo->getCString());

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

	//inicializando los sprites de arturo 
	

	_playerSprite = Sprite::create("images/Game2.1/1.png");

	_playerSprite->setPosition(Point(visibleSize.width / 6, _playerSprite->getContentSize().height / 1.2));
	_playerSprite->setScale(0.7f);

	addChild(_playerSprite, 1);
	

	
	// Configuramos la funcion de las teclas
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game21::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	//Coloca el Label donde se encuentra la puntuacion (numero de clicks ahora mismo)
	__String *text = __String::createWithFormat("Score %d    ", _score);
	_labelScore = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 24);
	_labelScore->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 30));

	String *tiempo = String::createWithFormat("time %d    ", _time);
	_timer = Label::createWithTTF(tiempo->getCString(), "fonts/Marker Felt.ttf", 24);
	_timer->setPosition(Vec2(150, visibleSize.height - 30));

	//Timer

	addChild(_labelScore, 1);
	addChild(_timer, 1);
	this->schedule(schedule_selector(Game21::timer), 1.0);

	return true;
}
