#ifndef __SELECT_SCENE2_H__
#define __SELECT_SCENE2_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class SelectScene2 : public cocos2d::Layer
{
private:
	Sprite* easy;
public:
	int piece_selected;
	void startGame(Ref *pSender);

	void MainMenuScene(Ref *pSender);

	void SelectScene2::goToSelectScene(Ref *pSender);

	void goToGame22(Ref *pSender);

	void goToGame23(Ref *pSender);

	void checkResults();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SelectScene2);
};

#endif // __SELECT_SCENE2_H__
