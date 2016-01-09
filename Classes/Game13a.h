#ifndef __GAME11A_SCENE_H__
#define __GAME11A_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class Game13a : public cocos2d::Layer
{
	int fasefondo = 1;

public:
	Sprite *fondo;
	Sprite *cesar;
	int _time;

	void timer(float dt);

	void animfondo(float dt);


	void goToSelectScene(Ref *pSender);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Game13a);
};

#endif // __GAME11A_SCENE_H__
