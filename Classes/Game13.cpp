#include "Game13.h"
#include "Game13a.h"
#include "Game13b.h"
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


void Game13::goToOptionA(Ref *pSender) {
	auto scene = Game13a::createScene();
	Director::getInstance()->pushScene(scene);
}

void Game13::goToOptionB(Ref *pSender) {
	auto scene = Game13b::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game13::contador()
{

	_score ++;

	__String *text = __String::createWithFormat("Score %d    ", _score);
	_labelScore->setString(text->getCString());

	if (_score == 10)
	{
		_playerSprite->setTexture("images/Game1.1/rueda2.png");
		_button->setTexture("images/Game1.1/left.png");
		_aux = 1;
	}

	if (_score == 20)
	{
		_playerSprite->setTexture("images/Game1.1/rueda3.png");
		_button->setTexture("images/Game1.1/down.png");
		_aux = 2;
	}
	if (_score == 30)
	{

		_playerSprite->setTexture("images/Game1.1/rueda4.png");
		_button->setTexture("images/Game1.1/right.png");
		_aux = 3;
	}
	if (_score == 31) //para comprobar que funciona
	{

		Global::_game13 = 1;
		Game13::goToOptionA(this);
	}


}

Scene* Game13::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game13::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Game13::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	if (_pressedKey != EventKeyboard::KeyCode::KEY_UP_ARROW && _pressedKey != EventKeyboard::KeyCode::KEY_LEFT_ARROW && _pressedKey != EventKeyboard::KeyCode::KEY_DOWN_ARROW && _pressedKey != EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{

		Global::_game13 = -1;
		Game13::goToOptionB(this);

	}

	else
	{
		switch (_pressedKey) {

				case EventKeyboard::KeyCode::KEY_UP_ARROW: //0x1052
				if (_aux == 0)
				{
				Game13::contador();
				}
				else
				{
					Global::_game13 = -1;
					Game13::goToOptionB(this);
				}
					break;

				case EventKeyboard::KeyCode::KEY_LEFT_ARROW: //0x1051
					if (_aux == 1)
					{
						Game13::contador();
					}
					
					else
					{
					Global::_game13 = -1;
					Game13::goToOptionB(this);
					}
						break;
					case EventKeyboard::KeyCode::KEY_DOWN_ARROW: //0x1054 o 0x1050
					if (_aux == 2)
						Game13::contador();
					else
					{
					Global::_game13 = -1;
					Game13::goToOptionB(this);
					}
						break;
				case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: //0x1053
					if (_aux == 3)
						Game13::contador();
					else
					{
						Global::_game11 = -1;
						Game13::goToOptionB(this);
					}
						break;
				//default:
					//Global::_game11 = -1;
					//Game11::goToOptionB(this);
					//break;

		}
	}

		
	
}

void Game13::timer(float dt) {
	_time++;

	String *tiempo = String::createWithFormat("time %d    ", _time);
	_timer->setString(tiempo->getCString());

}

bool Game13::init()
{


	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Inicializando el Fondo

	auto background = Sprite::create("images/Game1.1/fondo.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	// Inicializando el Sprite del jugador

	_playerSprite = Sprite::create("images/Game1.1/neo.png");

	_playerSprite->setPosition(Point(visibleSize.width / 4, _playerSprite->getContentSize().height/2));
	_playerSprite->setScale(0.7f);

	addChild(_playerSprite, 1);

	//inicializando los sprites de rueda y fuego 
	_playerSprite = Sprite::create("images/Game1.1/Fuego.png");

	_playerSprite->setPosition(Point(visibleSize.width / 2, _playerSprite->getContentSize().height / 2));
	_playerSprite->setScale(0.7f);

	addChild(_playerSprite, 1);

	_playerSprite = Sprite::create("images/Game1.1/rueda.png");

	_playerSprite->setPosition(Point(visibleSize.width / 6, _playerSprite->getContentSize().height / 1.2));
	_playerSprite->setScale(0.7f);

	addChild(_playerSprite, 1);
	// Inicializando el Sprite del boton a pulsar

	_button = Sprite::create("images/Game1.1/up.png");

	_button->setPosition(Point(visibleSize.width / 8 , _button->getContentSize().height * 5));
	_button->setScale(2.0f);

	addChild(_button, 2);

	
	// Configuramos la funcion de las teclas
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game13::onKeyPressed, this);

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
	this->schedule(schedule_selector(Game13::timer), 1.0);

	return true;
}
