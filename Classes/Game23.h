#ifndef __GAME23_H__
#define __GAME23_H__

#include "cocos2d.h"
USING_NS_CC;

class Game23 : public Layer
{
	EventKeyboard::KeyCode _pressedKey;


	Sprite* background;
	Sprite* piece1;
	Sprite* piece2;
	Sprite* piece3;
	Sprite* piece4;
	Sprite* piece5;
	Sprite* piece6;
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



	int piece_selected;

	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(Game23);

	bool onPlace(float spriteX, float spriteY, float posX, float posY);
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