#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameSceneLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameSceneLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	_World = new World();
	this->addChild(_World);
    
	 schedule( CC_SCHEDULE_SELECTOR(GameSceneLayer::Update) );

    return true;
}

void GameSceneLayer::Update(float dT)
{
	_World->Update(dT);
}

void GameSceneLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

	delete _World;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
