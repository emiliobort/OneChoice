#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;
int GameScene::_maxScore = 0;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
	layer->setPhysicisWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void GameScene::goToPauseScene(Ref *pSender){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScene::goToGameOverScene(Ref *pSender){
	//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/ButtonClick.wav");
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameScene::update(float dt){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto background = Sprite::create("images/GameScreen/Game_Screen_Background.png");

	auto *move = (FiniteTimeAction *)MoveBy::create(2 / BACKGROUND_SPEED, Point(0, -visibleSize.height + background->getContentSize().height));

	move->retain();
	// Scrolls Background
	for (int i = 0; i < 2; i++)
	{
		if (_backgroundSpriteArray[i]->getPosition().y < (visibleSize.height*-0.5))
			_backgroundSpriteArray[i]->setPosition(Point(visibleSize.width / 2, visibleSize.height*1.5f));

		else
			_backgroundSpriteArray[i]->setPosition(Point(_backgroundSpriteArray[i]->getPosition().x, _backgroundSpriteArray[i]->getPosition().y - (BACKGROUND_SPEED * visibleSize.height*dt)));
	}

	if (_isMoving || _isMovingByMouse){
		Vec2 newPos = Vec2(_playerSprite->getPosition().x + _podVector.x, _playerSprite->getPosition().y + _podVector.y);
		if (newPos.x >= _playerSprite->getBoundingBox().size.width / 2 && newPos.x <= (visibleSize.width - _playerSprite->getBoundingBox().size.width / 2) && newPos.y >= _playerSprite->getBoundingBox().size.height / 2 && newPos.y <= (visibleSize.height - _playerSprite->getBoundingBox().size.height / 2)){
			_playerSprite->setPosition(newPos);
		}
		_isMovingByMouse = false;
	}
}

void GameScene::asteroidDone(Node *pSender){
	_score += 10;

	if (_score > GameScene::_maxScore)
		GameScene::_maxScore = _score;

	__String *text = __String::createWithFormat("Score %d    Max %d", _score, GameScene::_maxScore);
	_labelScore->setString(text->getCString());

	pSender->stopAllActions();
	_asteroids.remove(pSender);
	removeChild(pSender);
}

void GameScene::moveBackground(float dt){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto background = Sprite::create("images/GameScreen/Game_Screen_Background.png");

	auto *move = (FiniteTimeAction *)MoveBy::create(2 / BACKGROUND_SPEED, Point(0, -visibleSize.height + background->getContentSize().height));

	move->retain();
}

void GameScene::spawnAsteroid(float dt){

	Size visibleSize = Director::getInstance()->getVisibleSize();
	int asteroidIndex = (std::rand() % 3 + 1);
	__String *filename = __String::createWithFormat("images/GameScreen/Asteroid_%i.png", asteroidIndex);
	
	Sprite *tempAsteroid = Sprite::create(filename->getCString());

	int xRandomPosition = (std::rand() % (int)(visibleSize.width - tempAsteroid->getContentSize().width)) + tempAsteroid->getContentSize().width / 2;

	tempAsteroid->setPosition(Point(xRandomPosition, visibleSize.height + tempAsteroid->getContentSize().height));

	/*Cada asteroide tendrá ahora un physicbody*/
	auto body = PhysicsBody::createCircle(tempAsteroid->getBoundingBox().size.width / 2);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	tempAsteroid->setPhysicsBody(body);

	auto *move = (FiniteTimeAction *)MoveBy::create(2 / METEOR_SPEED, Point(0, -visibleSize.height + tempAsteroid->getContentSize().height));

	move->retain();

	auto *seq = Sequence::create(move, CallFuncN::create(CC_CALLBACK_1(GameScene::asteroidDone, this)), NULL);

	seq->retain();

	_asteroids.push_back(tempAsteroid);

	tempAsteroid->runAction(seq);

	int angle = (std::rand() % 360) - 180;
	Action *rotate = RepeatForever::create(RotateBy::create(0.5, angle));

	rotate->retain();
	tempAsteroid->runAction(rotate);

	addChild(tempAsteroid, 2);
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event){
	_pressedKey = keyCode;

	switch (_pressedKey){
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			_podVector = Vec2(0, POD_STEP_MOVE);
			_isMoving = true;
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			_podVector = Vec2(0, -POD_STEP_MOVE);
			_isMoving = true;
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			_podVector = Vec2(-POD_STEP_MOVE, 0);
			_isMoving = true;
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			_podVector = Vec2(POD_STEP_MOVE, 0);
			_isMoving = true;
			break;
		case EventKeyboard::KeyCode::KEY_SPACE:
			//call Pause Scene if use Space in keyboard
			GameScene::goToPauseScene(this);
			break;
		case EventKeyboard::KeyCode::KEY_M:
			//Mute music
			if (!musicMuted){
				CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
				musicMuted = true;
			}
			else{
				CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
				musicMuted = false;
			}
			break;
	}
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event){
	if (_pressedKey==keyCode)
	{
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		_isMoving = false;
		_podVector = Vec2::ZERO;
	}
}

void GameScene::onMouseMove(Event *event){
	static Vec2 *oldPosition;
	auto *e = dynamic_cast<EventMouse *>(event);

	if (oldPosition==NULL)
	{
		oldPosition = new Vec2(e->getCursorX(), e->getCursorY());
	}
	else
	{
		_podVector = Vec2(e->getCursorX() - oldPosition->x, e->getCursorY() - oldPosition->y);
		if (!_isMovingByMouse)
		{
			_isMovingByMouse = true;
			oldPosition->x = e->getCursorX();
			oldPosition->y = e->getCursorY();
		}
	}
}

void GameScene::setPhysicisWorld(PhysicsWorld *world){
	mWorld = world;
	mWorld->setGravity(Vec2::ZERO);
}

bool GameScene::onContactBegin(PhysicsContact &contact){
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Crash.wav");
	goToGameOverScene(this);
	return true;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//for keyboard
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	_podVector = Vec2::ZERO;
	_isMoving = false;

	//for mouse
	_isMovingByMouse = false;

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
	// Creating Menu

	//auto asteroid1 = MenuItemImage::create("images/GameScreen/Asteroid_1.png", "images/GameScreen/Asteroid_1.png");

	//auto asteroid2 = MenuItemImage::create("images/GameScreen/Asteroid_2.png", "images/GameScreen/Asteroid_2.png");

	//auto asteroid3 = MenuItemImage::create("images/GameScreen/Asteroid_3.png", "images/GameScreen/Asteroid_3.png");

	//auto player = MenuItemImage::create("images/GameScreen/Space_Pod.png", "images/GameScreen/Space_Pod.png");
	
	auto pauseItem = MenuItemImage::create("images/GameScreen/Pause_Button.png", "images/GameScreen/Pause_Button(Click).png", CC_CALLBACK_1(GameScene::goToPauseScene, this));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(35,visibleSize.width - 35);
	addChild(menu, 1);
	

	//Loading scrollable background

	//Hay que hacerlo usando acciones y no tengo ni idea de como se hace

	for (int i = 0; i < 2; i++)
	{
		_backgroundSpriteArray[i] = Sprite::create("images/GameScreen/Game_Screen_Background.png");
		_backgroundSpriteArray[i]->setPosition(Point(visibleSize.width / 2, visibleSize.height + (i + 0.5f)));

		addChild(_backgroundSpriteArray[i], 0);
	}
	
	//Loading player sprite

	_playerSprite = Sprite::create("images/GameScreen/Space_Pod.png");

	_playerSprite->setPosition(Point(visibleSize.width / 2, _playerSprite->getContentSize().height*0.75));

	addChild(_playerSprite, 1);

	this->scheduleUpdate();

	this->schedule(schedule_selector(GameScene::spawnAsteroid), 1.0);

	//this->schedule(schedule_selector(GameScene::moveBackground), 1.0);

	//Setting and binding keyboard callbacks
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// Setting and binding mouse callbacks

	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);

	//PhysicsBody for each Sprite

	auto body = PhysicsBody::createCircle(_playerSprite->getBoundingBox().size.width / 2);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	_playerSprite->setPhysicsBody(body);

	//if meteor impact with pod
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	//Label

	__String *text = __String::createWithFormat("Score %d    MAX %d", _score, GameScene::_maxScore);
	_labelScore = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 24);
	_labelScore->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 30));

	addChild(_labelScore, 3);
	return true;
}