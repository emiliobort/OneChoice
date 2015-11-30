
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


public:

	Sprite *_backgroundSpriteArray[2];

	void Game13::setPhysicisWorld(PhysicsWorld *world);

	bool Game13::onContactBegin(PhysicsContact &contact);

	void Game13::goToSelectScene(Ref *pSender);

	//Sprite del jugador
	Sprite *_playerSprite;

	//Sprite boton
	Sprite *_button;

	//Funcion que controla el boton que se pulsa
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);

	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	void update(float dt);

	void contador();

	void goToOptionA(Ref *pSender);

	void goToOptionB(Ref *pSender);

	void timer(float dt);

	//Funcion para crear la escena
	static cocos2d::Scene* createScene();

	//Funcion para inicializar la escena
	virtual bool init();

	CREATE_FUNC(Game13);
};
