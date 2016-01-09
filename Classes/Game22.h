#ifndef __GAME22_H__
#define __GAME22_H__

#include "cocos2d.h"
USING_NS_CC;

class Game22 : public Layer
{

	EventKeyboard::KeyCode _pressedKey;


	Sprite* background;
	Sprite* interruptor;
	Sprite* bombilla;

	Vec2 posMouse;

	int _time = 0;
	Label *_timer;

	bool salida = false;
	bool gameOn = false;

public:	

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);

	
	int checkpoint = 0;


	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(Game22);

	void check(float mouseX, float mouseY);

	bool onTheWay(float mouseX, float mouseY);
	bool isFinished();

	void onMouseMove(Event *event);

	void goToOptionA(Ref *pSender);

	void goToOptionB(Ref *pSender);

	void timer(float dt);

	static Size screen()
	{
		return Director::getInstance()->getWinSize();
	}

};
#endif //__GAME22_H__