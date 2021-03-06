#include "Game13.h"
#include "Game13a.h"
#include "Game13b.h"
#include "Global.h"
#include "SelectScene.h"

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

void Game13::goToSelectScene(Ref *pSender) {
	auto scene = SelectScene::createScene();

	Director::getInstance()->replaceScene(TransitionFlipY::create(1.0, scene));;
}

void Game13::update(float dt) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto background = Sprite::create("images/Game1.3/fondo_completo.jpg");
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
	//mWorld->setGravity(Vec2::ZERO);
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
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			Global::_game13 = 1;
			goToOptionA(this);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			Global::_game13 = -1;
			goToOptionB(this);
			break;
		default:
			break;
	}
	CCLOG("%d", position);
}

void Game13::timer(float dt) {
	

}

void Game13::animEnemigo(float dt)
{

}

void Game13::animJugador(float dt)
{
	switch (fasejugador)
	{
	case(1) :
		player->setTexture("images/Game1.3/Jugador/CuadrigaA2.png");
		fasejugador = 2;
		break;
	case(2) :
		player->setTexture("images/Game1.3/Jugador/CuadrigaA3.png");
		fasejugador = 3;
		break;
	case(3) :
		player->setTexture("images/Game1.3/Jugador/CuadrigaA1.png");
		fasejugador = 1;
		break;
	default:
		break;
	}
}

void Game13::checkColission(int x, int y) {
	switch (position)
	{
	case(1) :
		if (x<200 + 320 / 2 - 1)
			if (y>520.0f && y < 560.0f) {
				Global::_game13 = -1;
				goToOptionB(this);
	}
		break;
	case(0) :
		if (x<200 + 320 / 2 - 1)
			if (y>330.0f && y < 570.0f) {
				Global::_game13 = -1;
				goToOptionB(this);
			}
		break;
	case(-1) :
		if (x <200 + 320 - 1)
			if (y>540.0f && y < 580.0f)
			{
				Global::_game13 = -1;
				goToOptionB(this);
			}
		break;
	default:
		break;
	}
}

void Game13::spawnEnemy(float dt) {
 int enemyIndex = (std::rand() % 2 );
 __String *filename = __String::createWithFormat("images/Game1.3/Cuadriga%i1.png",enemyIndex);
 Sprite *tempEnemy = Sprite::create(filename->getCString());
 tempEnemy->setScale(0.9f);
 int yRandomPosition = (std::rand() % 3 -1);
 int posY;
 switch (yRandomPosition)
 {
 case(1) :
	 posY = 540.0f;
	 break;
 case(0) :
	 posY = 350.0f;
	 break;
 case(-1) :
	 posY = 160.0f;
	 break;
 default:
	 break;
 }
 tempEnemy->setPosition(Point(screen().width,posY));

 



 
 
 
 //Arreglar movimiento de los carros y colisiones









 //auto *move = (FiniteTimeAction *)MoveBy::create(3.0f, Vec2(-screen().width*3.99, screen().height / 2 - tempEnemy->getBoundingBox().size.height));
 auto *move = (FiniteTimeAction *)MoveBy::create(3.0f, Vec2(-screen().width*3.99, tempEnemy->getPositionY()));
 move->retain();

 checkColission(tempEnemy->getPositionX(),tempEnemy->getPositionY());

 auto *seq = Sequence::create(move, CallFuncN::create(CC_CALLBACK_1(Game13::enemyDone, this)), NULL);
 seq->retain();

 _enemigos.push_back(tempEnemy);

 tempEnemy->runAction(seq);
	
	addChild(tempEnemy, 2);
}void Game13::enemyDone(Node *pSender) {
	pSender->stopAllActions();
	_enemigos.remove(pSender);
	removeChild(pSender);
}

bool Game13::init()
{
	//for keyboard
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;

	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto backItem = MenuItemImage::create("images/flechas/inicio.png", "images/flechas/inicio.png", CC_CALLBACK_1(Game13::goToSelectScene, this));
	auto back = Menu::create(backItem, NULL);
	back->setPosition(Vec2(0, 0));
	back->setScale(0.5f);
	back->setPosition(Vec2(1150 / 1.25, 650 / 1.3));
	addChild(back, 3);


	//esto hay que descomentarlo despues del testing
	this->background = Sprite::create("images/Game1.3/fondo_completo.jpg");
	this->background->setPosition(screen().width / 2 - 10, screen().height / 2 - 10);
	this->addChild(background, -1);

	this->player = Sprite::create("images/Game1.3/Jugador/CuadrigaA1.png");
	this->player->setPosition(200, 350);
	this->player->setScale(0.9f);
	this->addChild(player, 10);

	
	//esto hay que descomentarlo despues del testing 
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game13::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto *move = (Action *)MoveTo::create(30.0f, Point(-screen().width*3.99, screen().height / 2));
	background->runAction(move);

	this->scheduleUpdate();

	this->schedule(schedule_selector(Game13::spawnEnemy), 0.8f);

	this->schedule(schedule_selector(Game13::animJugador), 0.3f);

	Global::phase = 0;

	if (Global::musicPlayed) {
		auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
		audio->playBackgroundMusic("audio/juego/cesar.mp3", true);
		audio->setBackgroundMusicVolume(0.7f);
	}

	return true;
}

