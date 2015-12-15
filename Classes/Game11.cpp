#include "Game11.h"
#include "Game11a.h"
#include "Game11b.h"
#include "Global.h"
#include "SimpleAudioEngine.h"

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

	/*__String *text = __String::createWithFormat("Score %d    ", _score);
	_labelScore->setString(text->getCString());*/

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
		Global::_game11 = 1;
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

	if (_pressedKey != EventKeyboard::KeyCode::KEY_UP_ARROW && _pressedKey != EventKeyboard::KeyCode::KEY_LEFT_ARROW && _pressedKey != EventKeyboard::KeyCode::KEY_DOWN_ARROW && _pressedKey != EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{

		Global::_game11 = -1;
		Game11::goToOptionB(this);

	}

	else
	{
		switch (_pressedKey) {

				case EventKeyboard::KeyCode::KEY_UP_ARROW: //0x1052
				if (_aux == 0)
				{
				Game11::contador();
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Crash.wav");
				}
				else
				{
					Global::_game11 = -1;
					Game11::goToOptionB(this);
				}
					break;

				case EventKeyboard::KeyCode::KEY_LEFT_ARROW: //0x1051
					if (_aux == 1)
					{
						Game11::contador();
						CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Crash.wav");
					}
					
					else
					{
					Global::_game11 = -1;
					Game11::goToOptionB(this);
					}
						break;
				case EventKeyboard::KeyCode::KEY_DOWN_ARROW: //0x1054 o 0x1050

					if (_aux == 2)
					{
						Game11::contador();
						CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Crash.wav");

					}
						
					else
					{
					Global::_game11 = -1;
					Game11::goToOptionB(this);
					}
						break;
				case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: //0x1053
					if (_aux == 3)
					{
						Game11::contador();
						CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Crash.wav");

					}
						
					else
					{
						Global::_game11 = -1;
						Game11::goToOptionB(this);
					}
						break;
		}
	}

		
	
}

void Game11::timer(float dt) {
	_time++;

	String *tiempo = String::createWithFormat("%d", Global::_max_time-_time);
	_timer->setString(tiempo->getCString());

	if (_time == Global::_max_time)
	{
		Global::_game11 = -1;
		goToOptionB(this);
	}
}

bool Game11::init()
{

	
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//Inicializar audio
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Crash.mp3");


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

	//inicializando los sprites de texto de kao  
	/*_playerSprite = Sprite::create("images/Game1.1/texto_neandertal01.png");

	_playerSprite->setPosition(Point(visibleSize.width / 2, _playerSprite->getContentSize().height / 1.1));
	_playerSprite->setScale(0.4f);

	addChild(_playerSprite, 1);*/



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

	listener->onKeyPressed = CC_CALLBACK_2(Game11::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	String *tiempo = String::createWithFormat("");
	_timer = Label::createWithTTF(tiempo->getCString(), "fonts/trebuc.ttf", 48);
	_timer->setPosition(Vec2(visibleSize.width-90, visibleSize.height - 50));
	_timer->setTextColor(Color4B::WHITE);
	_timer->setScale(1.3);

	//Timer

	addChild(_timer, 1);
	this->schedule(schedule_selector(Game11::timer), 1.0);

	return true;
}