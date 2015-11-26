#include "Game11.h"
#include "Game11a.h"
#include "Game11b.h"
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


void Game11::goToOptionA(Ref *pSender) {
	auto scene = Game11a::createScene();
	Director::getInstance()->pushScene(scene);
}

void Game11::goToOptionB(Ref *pSender) {
	auto scene = Game11b::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game11::contador()
{

	_score ++;

	__String *text = __String::createWithFormat("Score %d    ", _score);
	_labelScore->setString(text->getCString());

	if (_score == 10)
	{
		_playerSprite->setTexture("images/squirtle.png");
		_button->setTexture("images/left.png");
		_aux = 1;
	}
	if (_score == 20)
	{
		_playerSprite->setTexture("images/charizard.png");
		_button->setTexture("images/right.png");
		_aux = 2;
	}
	if (_score == 30)
	{
		Global::_test = 1;
		Game11::goToOptionA(this);
	}


}

Scene* Game11::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game11::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Game11::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_UP_ARROW: //0x1052
		if (_aux==0) 
		{
			Game11::contador();
		}
		else 
		{
			Global::_test = -1;
			Game11::goToOptionB(this);
		}
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW: //0x1051
		if (_aux==1)
			Game11::contador();
		else
		{
			Global::_test = -1;
			Game11::goToOptionB(this);
		}
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: //0x1053
		if (_aux==2)
			Game11::contador();
		else
		{
			Global::_test = -1;
			Game11::goToOptionB(this);
		}
		break;
	}
}

//Con esto usamos el contador, una cosa que tengo que explicaros
void Game11::timer(float dt) {
	_time++;

	String *tiempo = String::createWithFormat("time %d    ", _time);
	_timer->setString(tiempo->getCString());

}

bool Game11::init()
{


	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Inicializando el Fondo

	auto background = Sprite::create("images/deadpool.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	// Inicializando el Sprite del jugador

	_playerSprite = Sprite::create("images/pikachu.png");

	_playerSprite->setPosition(Point(visibleSize.width / 2, _playerSprite->getContentSize().height/4));
	_playerSprite->setScale(0.5);

	addChild(_playerSprite, 1);

	// Inicializando el Sprite del boton a pulsar

	_button = Sprite::create("images/up.png");

	_button->setPosition(Point(visibleSize.width / 6 , _button->getContentSize().height * 1.1));
	_button->setScale(0.1);

	addChild(_button, 2);

	// Configuramos la funcion de las teclas
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game11::onKeyPressed, this);

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
	this->schedule(schedule_selector(Game11::timer), 1.0);

	return true;
}

