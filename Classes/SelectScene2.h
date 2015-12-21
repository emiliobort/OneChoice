#ifndef __SELECT_SCENE2_H__
#define __SELECT_SCENE2_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class SelectScene2 : public cocos2d::Layer
{
public:
	void startGame(Ref *pSender);

	void MainMenuScene(Ref *pSender);

	void SelectScene2::goToSelectScene(Ref *pSender);

	void goToGame12(Ref *pSender);

	void goToGame13(Ref *pSender);

	void checkResults();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SelectScene2);
};

#endif // __SELECT_SCENE2_H__
