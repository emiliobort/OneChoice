#ifndef __GAME23_H__
#define __GAME23_H__

#include "cocos2d.h"
USING_NS_CC;

class Game23 : public Layer
{
	EventKeyboard::KeyCode _pressedKey;


	Sprite* background;
	Sprite* sacos1;
	Sprite* sacos2;
	Sprite* sacos3;
	Sprite* sacos4;
	Sprite* sacos5;
	Sprite* sacos6;
	Sprite* sacos7;
	Sprite* sacos8;
	bool piece1_placed = false;
	bool piece2_placed = false;
	bool piece3_placed = false;
	bool piece4_placed = false;
	bool piece5_placed = false;
	bool piece6_placed = false;

	int _time = 0;
	Label *_timer;

public:


	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);



	int muertos=0;

	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(Game23);

	void naziDead(int naziID);
	bool isFinished();

	void goToOptionA(Ref *pSender);

	void goToOptionB(Ref *pSender);

	void timer(float dt);

	static Size screen()
	{
		return Director::getInstance()->getWinSize();
	}

};
#endif //__GAME23_H__