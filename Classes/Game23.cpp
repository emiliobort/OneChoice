#include "Game23.h"
#include "Game23a.h"
#include "Game23b.h"

#include "Global.h"
#include "SelectScene.h"

USING_NS_CC;


Scene* Game23::createScene()
{
	auto scene = Scene::create();
	auto layer = Game23::create();
	scene->addChild(layer);
	return scene;
}

void Game23::goToOptionA(Ref *pSender) {
	auto scene = Game23a::createScene();
	Director::getInstance()->pushScene(scene);
}

void Game23::goToOptionB(Ref *pSender) {
	auto scene = Game23b::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Game23::naziDead(int naziID)
{
	auto fadeOut = FadeOut::create(2.0f);
	switch (naziID)
	{
	case 1:
		piece4->runAction(fadeOut);
		break;
	case 2:
		piece5->runAction(fadeOut);
		break;
	case 3:
		piece6->runAction(fadeOut);
		break;
	default:
		break;
	}
	return;
}

bool Game23::isFinished()
{
	return false;
}

void Game23::timer(float dt) {
	_time++;

	String *tiempo = String::createWithFormat("%d", Global::_max_time*2 - _time);
	_timer->setString(tiempo->getCString());

	if (_time == Global::_max_time*2)
	{
		Global::_game23 = -1;
		goToOptionB(this);
	}
}

void Game23::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		Global::_game23 = 1;
		goToOptionA(this);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		Global::_game23 = -1;
		goToOptionB(this);
		break;
	default:
		break;
	}
}






// Cargar a Hitler y que se mueva Tambien hay que añadir los disparos y algo para poder perder









bool Game23::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Game23::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	piece_selected = 0;

	this->background = Sprite::create("images/Game2.3/escenario.jpg");
	this->background->setPosition(Game23::screen().width / 2, Game23::screen().height / 2);
	this->addChild(background, -1);

	this->piece1 = Sprite::create("images/Game2.3/sacos1.png"); // pajaro
	this->piece1->setPosition(540, 190);
	this->addChild(piece1, 9);

	this->piece2 = Sprite::create("images/Game2.3/sacos2.png"); // pie
	this->piece2->setPosition(940, 355);
	this->addChild(piece2, 7);

	this->piece3 = Sprite::create("images/Game2.3/sacos3.png"); // ojo
	this->piece3->setPosition(360, 440);
	this->addChild(piece3, 5);

	this->piece4 = Sprite::create("images/Game2.3/nazi1.png"); // escarabajo
	this->piece4->setPosition(575, 310);
	this->addChild(piece4, 8);

	this->piece5 = Sprite::create("images/Game2.3/nazi2.png"); // cruz
	this->piece5->setPosition(930, 450);
	this->addChild(piece5, 6);

	this->piece6 = Sprite::create("images/Game2.3/nazi3.png"); // gato
	this->piece6->setPosition(380, 520);
	this->addChild(piece6, 4);

	this->piece7 = Sprite::create("images/Game2.3/tanque.png"); // gato
	this->piece7->setPosition(0, 250);
	this->addChild(piece7, 10);

	auto moveBy = MoveBy::create(30, Vec2(2500, 0));

	piece7->runAction(moveBy);

	auto event_listener = EventListenerTouchAllAtOnce::create();

	Size visibleSize = Director::getInstance()->getVisibleSize();


	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();
		
		float distance;
			distance = this->piece4->getPosition().getDistance(touch->getLocation());
			if (distance < 80) {
				naziDead(1);
				piece4->setTexture("images/Game2.3/nazi1d.png");
				return;
			}

			distance = this->piece5->getPosition().getDistance(touch->getLocation());
			if (distance < 80) {
				naziDead(2);
				piece5->setTexture("images/Game2.3/nazi2d.png");
				return;
			}

			distance = this->piece6->getPosition().getDistance(touch->getLocation());
			if (distance < 80) {
				naziDead(3);
				piece6->setTexture("images/Game2.3/nazi3d.png");
				return;
			}
	};

	event_listener->onTouchesEnded = [=](const std::vector<Touch*>& pTouches, Event* event) {

		piece_selected = 0;
		if (isFinished())
		{
			Global::_game23 = 1;
			goToOptionA(this);
		}
	};

	event_listener->onTouchesMoved = [=](const std::vector<Touch*>& pTouches, Event* event) {

		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		auto move_action = MoveTo::create(0.001f, openGl_location);

		if (piece_selected == 1) {
			piece1->setPosition(touch->getLocation());
		}
		if (piece_selected == 2) {
			piece2->setPosition(touch->getLocation());
		}
		if (piece_selected == 3) {
			piece3->setPosition(touch->getLocation());
		}
		if (piece_selected == 4) {
			piece4->setPosition(touch->getLocation());
		}
		if (piece_selected == 5) {
			piece5->setPosition(touch->getLocation());
		}
		if (piece_selected == 6) {
			piece7->setPosition(touch->getLocation());
		}
	};

	String *tiempo = String::createWithFormat("");
	_timer = Label::createWithTTF(tiempo->getCString(), "fonts/trebuc.ttf", 48);
	_timer->setPosition(Vec2(visibleSize.width - 90, visibleSize.height - 50));
	_timer->setTextColor(Color4B::WHITE);
	_timer->setScale(1.3);

	//Timer

	addChild(_timer, 1);
	this->schedule(schedule_selector(Game23::timer), 1.0);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, piece1);

	return true;
}
