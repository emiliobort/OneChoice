#ifndef __GAME13_H__
#define __GAME13_H__

#pragma once

#include "cocos2d.h"

USING_NS_CC;
class Game13 : public cocos2d::Layer
{
private:
	int fasejugador=1;
	int faseenemigo=1;

	void animJugador(float dt);

	void animEnemigo(float dt);

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
	Sprite* enemigo;

public:


	std::list<cocos2d::Node *> _enemigos;
	
	int position;

	void spawnEnemy(float dt);
	void enemyDone(Node *pSender);


	void setPhysicisWorld(PhysicsWorld *world);

	bool onContactBegin(PhysicsContact &contact);

	void goToSelectScene(Ref *pSender);

	void Game13::checkColission(int x, int y);

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