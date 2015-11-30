#ifndef __SELECT_SCENE_H__
#define __SELECT_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class SelectScene : public cocos2d::Layer
{
public:

	bool musicMuted;

	void pauseMusic();

	void startGame(Ref *pSender);

	void SelectScene::MainMenuScene(Ref *pSender);

	void SelectScene::goToGame12(Ref *pSender);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SelectScene);
};

#endif // __MAINMENU_SCENE_H__
