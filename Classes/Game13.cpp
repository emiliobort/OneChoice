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
	/*Size visibleSize = Director::getInstance()->getVisibleSize();
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
	}*/
}

void Game13::updatePosition(int i) 
{
	if (i == -1) {
		player->setPositionY(540.0f);
		return;
	}
	if (i == 0) {
		player->setPositionY(350.0f);
		return;
	}
	if (i == 1) {
		player->setPositionY(160.0f);
		return;
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
	auto scene = Scene::createWithPhysics();
	auto layer = Game13::create();
	scene->addChild(layer);
	return scene;
}

void Game13::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
		case EventKeyboard::KeyCode::KEY_UP_ARROW: //0x1052
			if (position != -1) 
			{
				position--;
				updatePosition(position);
			}
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			if (position != 1)
			{
				position++;
				updatePosition(position);
			}
			break;
		default:
			break;
	}
	CCLOG("%d", position);
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



	/*auto background = Sprite::create("images/enConstruccion.jpg");

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

	Size visibleSize = Director::getInstance()->getVisibleSize();


	this->background = Sprite::create("images/Game1.3/fondo2.jpg");
	this->background->setPosition(Game13::screen().width / 2 - 10, Game13::screen().height / 2 - 10);
	this->addChild(background, -1);

	this->player = Sprite::create("images/Game1.3/Jugador.png"); // pajaro
	this->player->setPosition(200, 350);
	this->addChild(player, 10);


	/*auto event_listener = EventListenerTouchAllAtOnce::create();

	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distance;
		distance = this->player->getPosition().getDistance(touch->getLocation());
		if (distance < 30) {
			return;
		}
	};

	event_listener->onTouchesEnded = [=](const std::vector<Touch*>& pTouches, Event* event) {

		CCLOG("%f %f", player->getPositionX(), player->getPositionY());
	};

	event_listener->onTouchesMoved = [=](const std::vector<Touch*>& pTouches, Event* event) {

		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		auto move_action = MoveTo::create(0.001f, openGl_location);

		player->setPosition(touch->getLocation());
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, player);*/

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game13::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

