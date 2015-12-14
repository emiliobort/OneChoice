#ifndef __GAME13_H__
#define __GAME13_H__

#pragma once

#include "cocos2d.h"

USING_NS_CC;
class Game13 : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;
	Vec2 _carro;
	bool _isMoving;

	PhysicsWorld *mWorld;

	int _score = 0;
	Label *_labelScore;
	int _aux = 0;

	int _time = 0;
	Label *_timer;


	Sprite* background;
	Sprite* player;

public:

	int position;

	void Game13::setPhysicisWorld(PhysicsWorld *world);

	bool Game13::onContactBegin(PhysicsContact &contact);

	void Game13::goToSelectScene(Ref *pSender);

	//Sprite boton
	Sprite *_button;

	//Funcion que controla el boton que se pulsa
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);

	void update(float dt);

	void updatePosition(int i);

	void goToOptionA(Ref *pSender);

	void goToOptionB(Ref *pSender);

	void timer(float dt);

	//Funcion para crear la escena
	static cocos2d::Scene* createScene();

	//Funcion para inicializar la escena
	virtual bool init();

	static Size screen()
	{
		return Director::getInstance()->getWinSize();
	}

	CREATE_FUNC(Game13);
};
#endif //__GAME13_H__