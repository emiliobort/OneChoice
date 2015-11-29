#ifndef __OPTIONS_SCENE_H__
#define __OPTIONS_SCENE_H__
#pragma once

#include "cocos2d.h"
USING_NS_CC;

class OptionsScene : public cocos2d::Layer
{
private:
	Label *_game1_1;
	Label *_game1_2;
	Label *_game1_3;
	Label *_game2_1;
	Label *_game2_2;
	Label *_game2_3;
public:

	void goToMainMenu(Ref *pSender);

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(OptionsScene);
};

#endif // __OPTIONS_SCENE_H__
