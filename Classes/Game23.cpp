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
		sacos4->runAction(fadeOut);
		muertos++;
		
		break;
	case 2:
		sacos5->runAction(fadeOut);
		muertos++;
		
		break;
	case 3:
		sacos6->runAction(fadeOut);
		muertos++;
		
		break;
	case 4:
		muertos++;
		
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

	String *tiempo = String::createWithFormat("%d", Global::_max_time - _time);
	_timer->setString(tiempo->getCString());

	if (_time == Global::_max_time)
	{
		if (muertos == 4)
		{
			Global::_game23 = 1;
			goToOptionA(this);
		}
		else
		{
			Global::_game23 = -1;
			goToOptionB(this);
		}

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


	this->background = Sprite::create("images/Game2.3/escenario.jpg");
	this->background->setPosition(Game23::screen().width / 2, Game23::screen().height / 2);
	this->addChild(background, -1);

	this->sacos1 = Sprite::create("images/Game2.3/sacos1.png"); // pajaro
	this->sacos1->setPosition(540, 190);
	this->addChild(sacos1, 9);

	this->sacos2 = Sprite::create("images/Game2.3/sacos2.png"); // pie
	this->sacos2->setPosition(940, 355);
	this->addChild(sacos2, 7);

	this->sacos3 = Sprite::create("images/Game2.3/sacos3.png"); // ojo
	this->sacos3->setPosition(360, 440);
	this->addChild(sacos3, 5);

	this->sacos4 = Sprite::create("images/Game2.3/nazi1.png"); // escarabajo
	this->sacos4->setPosition(575, 310);
	this->addChild(sacos4, 8);

	this->sacos5 = Sprite::create("images/Game2.3/nazi2.png"); // cruz
	this->sacos5->setPosition(930, 450);
	this->addChild(sacos5, 6);

	this->sacos6 = Sprite::create("images/Game2.3/nazi3.png"); // gato
	this->sacos6->setPosition(380, 520);
	this->addChild(sacos6, 4);

	this->sacos7 = Sprite::create("images/Game2.3/tanque.png"); // gato
	this->sacos7->setPosition(-480, 250);
	this->addChild(sacos7, 10);

	this->sacos8 = Sprite::create("images/Game2.3/hitler.png"); // gato
	this->sacos8->setPosition(-595, 400);
	this->addChild(sacos8, 10);

	auto moveBy = MoveBy::create(Global::_max_time, Vec2(2240, 0));

	sacos7->runAction(moveBy);

	auto moveBy2 = MoveBy::create(Global::_max_time, Vec2(2240, 0));

	sacos8->runAction(moveBy2);

	auto event_listener = EventListenerTouchAllAtOnce::create();

	Size visibleSize = Director::getInstance()->getVisibleSize();


	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();
		
		float distance;
			distance = this->sacos4->getPosition().getDistance(touch->getLocation());
			if (distance < 80) {
				naziDead(1);
				sacos4->setTexture("images/Game2.3/nazi1d.png");
				return;
			}

			distance = this->sacos5->getPosition().getDistance(touch->getLocation());
			if (distance < 80) {
				naziDead(2);
				sacos5->setTexture("images/Game2.3/nazi2d.png");
				return;
			}

			distance = this->sacos6->getPosition().getDistance(touch->getLocation());
			if (distance < 80) {
				naziDead(3);
				sacos6->setTexture("images/Game2.3/nazi3d.png");
				return;
			}
			distance = this->sacos8->getPosition().getDistance(touch->getLocation());
			if (distance < 80) {
				naziDead(4);
				sacos8->setTexture("images/Game2.3/hitlerd.png");
				return;
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
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, sacos1);

	return true;
}
