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

bool Game23::onPlace(float spriteX, float spriteY, float posX, float posY)
{
	if (spriteX<posX + 20 && spriteX>posX - 20)
	{
		if (spriteY<posY + 20 && spriteY>posY - 20)
		{
			return true;
		}
	}
	return false;
}

bool Game23::isFinished()
{
	if (piece1_placed)
		if (piece2_placed)
			if (piece3_placed)
				if (piece4_placed)
					if (piece5_placed)
						if (piece6_placed)
							return true;
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

	auto event_listener = EventListenerTouchAllAtOnce::create();

	Size visibleSize = Director::getInstance()->getVisibleSize();


	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();
		
		float distance;
		if (!piece4_placed)
		{
			distance = this->piece4->getPosition().getDistance(touch->getLocation());
			if (distance < 30) {
				piece_selected = 4;
				return;
			}
		}
		if (!piece5_placed)
		{
			distance = this->piece5->getPosition().getDistance(touch->getLocation());
			if (distance < 30) {
				piece_selected = 5;
				return;
			}
		}
		if (!piece6_placed)
		{
			distance = this->piece6->getPosition().getDistance(touch->getLocation());
			if (distance < 30) {
				piece_selected = 6;
				return;
			}
		}
	};

	event_listener->onTouchesEnded = [=](const std::vector<Touch*>& pTouches, Event* event) {
		

		switch (piece_selected)
		{
		case 4:
			CCLOG("%f %f", piece4->getPositionX(), piece4->getPositionY());
		case 5:
			CCLOG("%f %f", piece5->getPositionX(), piece5->getPositionY());
		case 6:
			CCLOG("%f %f", piece6->getPositionX(), piece6->getPositionY());
		default:
			break;
		}

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
			piece6->setPosition(touch->getLocation());
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
