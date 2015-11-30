#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
class Kao : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;

	int _score = 0;
	int _aux = 0;

public:
	void startGame(Ref *pSender);
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);

	void contador();

	void Kao::goToSelectScene(Ref *pSender);


	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Kao);
};

