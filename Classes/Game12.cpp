#include "Game12.h"
#include "Game12a.h"
#include "Game12b.h"

#include "Global.h"
#include "SelectScene.h"

USING_NS_CC;

/*		Lista de posiciones de las piezas

	pajaro			 901.6		 656.5
	pie				 1036.3		 152.3
	ojo				 690.9		 151.3
	escarabajo		 864.6		 271.1
	cruz			 298.6		 529.7
	gato			 483.3		 408.9

*/


Scene* Game12::createScene()
{
	auto scene = Scene::create();
	auto layer = Game12::create();
	scene->addChild(layer);
	return scene;
}

void Game12::goToOptionA(Ref *pSender) {
	auto scene = Game12a::createScene();
	Director::getInstance()->pushScene(scene);
}

void Game12::goToOptionB(Ref *pSender) {
	auto scene = Game12b::createScene();
	Director::getInstance()->replaceScene(scene);
}

bool Game12::onPlace(float spriteX, float spriteY, float posX, float posY)
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

bool Game12::isFinished()
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

void Game12::timer(float dt) {
	_time++;

	String *tiempo = String::createWithFormat("%d", Global::_max_time*2 - _time);
	_timer->setString(tiempo->getCString());

	if (_time == Global::_max_time*2)
	{
		Global::_game12 = -1;
		goToOptionB(this);
	}
}

bool Game12::init()
{
	if (!Layer::init())
	{
		return false;
	}
	piece_selected = 0;

	this->background = Sprite::create("images/Game1.2/Escenario.jpg");
	this->background->setPosition(Game12::screen().width / 2, Game12::screen().height / 2);
	this->addChild(background, -1);

	this->piece1 = Sprite::create("images/Game1.2/piece1.png"); // pajaro
	this->piece1->setPosition(130, 430);
	this->addChild(piece1, 10);

	this->piece2 = Sprite::create("images/Game1.2/piece2.png"); // pie
	this->piece2->setPosition(130, 315);
	this->addChild(piece2, 10);

	this->piece3 = Sprite::create("images/Game1.2/piece3.png"); // ojo
	this->piece3->setPosition(130, 200);
	this->addChild(piece3, 10);

	this->piece4 = Sprite::create("images/Game1.2/piece4.png"); // escarabajo
	this->piece4->setPosition(1150, 430);
	this->addChild(piece4, 10);

	this->piece5 = Sprite::create("images/Game1.2/piece5.png"); // cruz
	this->piece5->setPosition(1150, 315);
	this->addChild(piece5, 10);

	this->piece6 = Sprite::create("images/Game1.2/piece6.png"); // gato
	this->piece6->setPosition(1150, 200);
	this->addChild(piece6, 10);

	auto event_listener = EventListenerTouchAllAtOnce::create();

	Size visibleSize = Director::getInstance()->getVisibleSize();


	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();
		
		float distance;
		if (!piece1_placed)
		{
			distance = this->piece1->getPosition().getDistance(touch->getLocation());
			if (distance < 30) {
				piece_selected = 1;
				return;
			}
		}
		if (!piece2_placed)
		{
			distance = this->piece2->getPosition().getDistance(touch->getLocation());
			if (distance < 30) {
				piece_selected = 2;
				return;
			}
		}
		if (!piece3_placed)
		{
			distance = this->piece3->getPosition().getDistance(touch->getLocation());
			if (distance < 30) {
				piece_selected = 3;
				return;
			}
		}
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
		case 1:
			if (onPlace(piece1->getPositionX(), piece1->getPositionY(), 902.0f, 656.5f)) {
				piece1->setPositionX(901.6f);
				piece1->setPositionY(656.5f);
				piece1_placed = true;
			}
		case 2:		 
			if (onPlace(piece2->getPositionX(), piece2->getPositionY(), 1037.0f, 152.3f)) {
				piece2->setPositionX(1036.3f);
				piece2->setPositionY(152.3f);
				piece2_placed = true;
			}
		case 3:
			if (onPlace(piece3->getPositionX(), piece3->getPositionY(), 691.0f, 147.3f)) {
				piece3->setPositionX(690.9f);
				piece3->setPositionY(147.3f);
				piece3_placed = true;
			}
		case 4:
			if (onPlace(piece4->getPositionX(), piece4->getPositionY(), 867.0f, 272.1f)) {
				piece4->setPositionX(869.6f);
				piece4->setPositionY(272.1f);
				piece4_placed = true;
			}
		case 5:
			if (onPlace(piece5->getPositionX(), piece5->getPositionY(), 298.0f, 530.7f)) {
				piece5->setPositionX(297.5f);
				piece5->setPositionY(530.7f);
				piece5_placed = true;
			}
		case 6:
			if (onPlace(piece6->getPositionX(), piece6->getPositionY(), 489.0f, 407.9f)) {
				piece6->setPositionX(488.2f);
				piece6->setPositionY(407.9f);
				piece6_placed = true;
			}
		default:
			break;
		}
		//CCLOG("%f %f", piece3->getPositionX(), piece3->getPositionY());
		piece_selected = 0;
		if (isFinished())
		{
			Global::_game12 = 1;
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
	this->schedule(schedule_selector(Game12::timer), 1.0);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, piece1);

	Global::phase = 0;

	if (Global::musicPlayed) {
		auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
		audio->playBackgroundMusic("audio/juego/egipcio.mp3", true);
		audio->setBackgroundMusicVolume(0.7f);
	}

	return true;
}
