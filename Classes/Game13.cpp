#include "Game13.h"
#include "Game13a.h"
#include "Game13b.h"
#include "Global.h"
#include "SelectScene.h"

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


void Game13::goToOptionA(Ref *pSender) {
	auto scene = Game13a::createScene();
	Director::getInstance()->pushScene(scene);
}

void Game13::goToOptionB(Ref *pSender) {
	auto scene = Game13b::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game13::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void Game13::update(float dt) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto background = Sprite::create("images/Game1.3/fondo2.jpg");

	auto *move = (FiniteTimeAction *)MoveBy::create(2 / 0.3f, Point(0, -visibleSize.height + background->getContentSize().height));

	move->retain();
	// Scrolls Background
	for (int i = 0; i < 2; i++)
	{
		if (_backgroundSpriteArray[i]->getPosition().y < (visibleSize.height*-0.5))
			_backgroundSpriteArray[i]->setPosition(Point(visibleSize.width / 2, visibleSize.height*1.5f));

		else
			_backgroundSpriteArray[i]->setPosition(Point(_backgroundSpriteArray[i]->getPosition().x, _backgroundSpriteArray[i]->getPosition().y - (0.3f * visibleSize.height*dt)));
	}
}

void Game13::setPhysicisWorld(PhysicsWorld *world) {
	mWorld = world;
	mWorld->setGravity(Vec2::ZERO);
}

bool Game13::onContactBegin(PhysicsContact &contact) {
	Global::_game13 = -1; 
	goToOptionB(this);
	return true;
}

Scene* Game13::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = Game13::create();
	layer->setPhysicisWorld(scene->getPhysicsWorld());

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Game13::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
		case EventKeyboard::KeyCode::KEY_UP_ARROW: //0x1052
			_carro = Vec2(0, 10);
			_isMoving = true;
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			_carro = Vec2(0, -10);
			_isMoving = true;
			break;
	}
}

void Game13::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (_pressedKey == keyCode)
	{
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		_isMoving = false;
		_carro = Vec2::ZERO;
	}
}

void Game13::timer(float dt) {
	_time++;

	String *tiempo = String::createWithFormat("time %d    ", _time);
	_timer->setString(tiempo->getCString());

}

bool Game13::init()
{
	//for keyboard
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	_carro = Vec2::ZERO;
	_isMoving = false;


	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create("images/enConstruccion.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(background, 0);

	auto backItem = MenuItemImage::create("images/SelectGame/Back.png", "images/SelectGame/Back_click.png", CC_CALLBACK_1(Game13::goToSelectScene, this));

	auto back = Menu::create(backItem, NULL);

	back->setPosition(Vec2(300, 450));

	addChild(back, 1);


	//A partir de aqui hay que tocar cosas, de momento dejo el apartado de en construccion
	/*
	//Loading scrollable background

	for (int i = 0; i < 2; i++)
	{
		_backgroundSpriteArray[i] = Sprite::create("images/Game1.3/fondo2.jpg");
		_backgroundSpriteArray[i]->setPosition(Point(visibleSize.width / 2 , visibleSize.height/2 + (i + 0.5f)));

		addChild(_backgroundSpriteArray[i], 0);
	}

	//Loading player sprite

	_playerSprite = Sprite::create("images/Game1.3/Jugador.png");

	_playerSprite->setPosition(Point(500,500));

	addChild(_playerSprite, 1);

	this->scheduleUpdate();

	//this->schedule(schedule_selector(GameScene::spawnAsteroid), 1.0);

	//this->schedule(schedule_selector(GameScene::moveBackground), 1.0);

	//Setting and binding keyboard callbacks
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game13::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//PhysicsBody for each Sprite

	auto body = PhysicsBody::createCircle(_playerSprite->getBoundingBox().size.width / 2);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	_playerSprite->setPhysicsBody(body);

	//if meteor impact with pod
	//auto contactListener = EventListenerPhysicsContact::create();
	//contactListener->onContactBegin = CC_CALLBACK_1(Game13::onContactBegin, this);
	//getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	*/

	return true;
}

