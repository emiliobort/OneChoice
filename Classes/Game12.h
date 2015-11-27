#pragma once
#include "cocos2d.h"

USING_NS_CC;
class Game12 : public cocos2d::Layer
{


public:
	//Sprite de las piezas
	Sprite *_piece1;

	void goToSelectScene(Ref *pSender);

	void goToOptionA(Ref *pSender);

	void goToOptionB(Ref *pSender);

	void timer(float dt);

	//Funcion para crear la escena
	static cocos2d::Scene* createScene();

	//Funcion para inicializar la escena
	virtual bool init();

	CREATE_FUNC(Game12);
};

