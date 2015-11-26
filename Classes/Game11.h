
#pragma once

#include "cocos2d.h"

USING_NS_CC;
class Game11 : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;

	int _score = 0;
	Label *_labelScore;
	int _aux = 0;

	int _time = 0;
	Label *_timer;


public:
	//Sprite del jugador
	Sprite *_playerSprite;

	//Sprite boton
	Sprite *_button;

	//Funcion que controla el boton que se pulsa
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);


	void contador();

	void Game11::goToOptionA(Ref *pSender);

	void Game11::goToOptionB(Ref *pSender);

	void Game11::timer(float dt);

	//Funcion para crear la escena
	static cocos2d::Scene* createScene();

	//Funcion para inicializar la escena
	virtual bool init();

	CREATE_FUNC(Game11);
};
