#ifndef __GAME12A_SCENE_H__
#define __GAME12A_SCENE_H__

#include "cocos2d.h"

class Game12a : public cocos2d::Layer
{
public:
	int _time;

	void timer(float dt);

	void goToSelectScene(Ref *pSender);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Game12a);
};

#endif // __GAME12A_SCENE_H__
