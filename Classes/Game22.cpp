#include "Game22.h"
#include "Game22a.h"
#include "Game22b.h"

#include "Global.h"
#include "SelectScene.h"

USING_NS_CC;


Scene* Game22::createScene()
{
	auto scene = Scene::create();
	auto layer = Game22::create();
	scene->addChild(layer);
	return scene;
}

void Game22::goToOptionA(Ref *pSender) {
	auto scene = Game22a::createScene();
	Director::getInstance()->pushScene(scene);
}

void Game22::goToOptionB(Ref *pSender) {
	auto scene = Game22b::createScene();
	Director::getInstance()->replaceScene(scene);
}

bool Game22::onTheWay(float mouseX, float mouseY)
{
	if (gameOn) {
		switch (checkpoint)
		{
		case 0:
			if (mouseX < 140 && mouseX>0 && mouseY < 410 && mouseY>270) {
				salida = true;
				if (mouseX < 545 && mouseX>0 && mouseY < 375 && mouseY>305) {
					salida = false;
					return true;
				}
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			break;

		}
	}
	if (salida) {
		salida = false;
		return true;
	}
	else
		return false;
}

void Game22::check(float mouseX, float mouseY)
{
	switch (checkpoint)
	{
	case 0:
		if (mouseX < 545 && mouseX >= 475 && mouseY < 375 && mouseY >= 305)
			checkpoint = 1;
		break;
	case 1:
		if (mouseX < 545 && mouseX>= 475 && mouseY < 690 && mouseY>= 630)
			checkpoint = 2;
		break;
	case 2:
		if (mouseX < 775 && mouseX>= 705 && mouseY < 690 && mouseY>= 630)
			checkpoint = 3;
		break;
	case 3:
		if (mouseX < 775 && mouseX>= 705 && mouseY < 245 && mouseY>= 185)
			checkpoint = 4;
		break;
	case 4:
		if (mouseX < 570 && mouseX>= 500 && mouseY < 245 && mouseY>= 185)
			checkpoint = 5;
		break;
	case 5:
		if (mouseX < 570 && mouseX>= 500 && mouseY < 100 && mouseY>= 50)
			checkpoint = 6;
		break;
	case 6:
		if (mouseX < 1100 && mouseX>= 1030 && mouseY < 100 && mouseY>= 50)
			checkpoint = 7;
		break;
	case 7:
		if (mouseX < 1100 && mouseX>= 1030 && mouseY >= 420) {
			checkpoint = 8;

		}
		break;
	case 8:

		break;
	default:
		break;
	}

	return;
}

bool Game22::isFinished()
{
	return false;
}

void Game22::timer(float dt) {
	_time++;

	String *tiempo = String::createWithFormat("%d", Global::_max_time*2 - _time);
	_timer->setString(tiempo->getCString());

	if (_time == Global::_max_time*2)
	{
		Global::_game22 = -1;
		goToOptionB(this);
	}
}








// COmpletar las partes correspondientes a los caminos









void Game22::onMouseMove(Event *event) {
	auto *e = dynamic_cast<EventMouse *>(event);
	posMouse.set(e->getCursorX(), e->getCursorY());
	check(e->getCursorX(), e->getCursorY());
	CCLOG("%f %f", e->getCursorX(), e->getCursorY());
	CCLOG("%i", checkpoint);
}

void Game22::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		Global::_game22 = 1;
		goToOptionA(this);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		Global::_game22 = -1;
		goToOptionB(this);
		break;
	default:
		break;
	}
}

bool Game22::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game22::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	this->background = Sprite::create("images/Game2.2/fondo2.jpg");
	this->background->setPosition(Game22::screen().width / 2, Game22::screen().height / 2);
	this->addChild(background, -1);

	this->interruptor = Sprite::create("images/Game2.2/interruptor_off.png"); 
	this->interruptor->setPosition(100, 330);
	this->addChild(interruptor, 10);

	this->bombilla = Sprite::create("images/Game2.2/bombilla_off.png");
	this->bombilla->setPosition(1063, 525);
	this->addChild(bombilla, 10);

	auto event_listener = EventListenerTouchAllAtOnce::create();

	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseMove = CC_CALLBACK_1(Game22::onMouseMove, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);


	Size visibleSize = Director::getInstance()->getVisibleSize();

	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();
		
		float distance;
		distance = this->interruptor->getPosition().getDistance(touch->getLocation());
		if (distance < 30)
			interruptor->setTexture("images/Game2.2/interruptor_on.png");
		
	};

	String *tiempo = String::createWithFormat("");
	_timer = Label::createWithTTF(tiempo->getCString(), "fonts/trebuc.ttf", 48);
	_timer->setPosition(Vec2(visibleSize.width - 90, visibleSize.height - 50));
	_timer->setTextColor(Color4B::WHITE);
	_timer->setScale(1.3);

	//Timer

	addChild(_timer, 1);
	this->schedule(schedule_selector(Game22::timer), 1.0);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, interruptor);

	return true;
}
