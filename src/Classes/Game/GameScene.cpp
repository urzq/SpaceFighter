#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2::ZERO);

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
	if (Layer::init())
	{
		World::Init();
		_World = &World::GetInstance();
		this->addChild(_World);

		schedule(CC_SCHEDULE_SELECTOR(GameSceneLayer::Update));

		auto contactListener = EventListenerPhysicsContact::create();

		contactListener->onContactBegin = CC_CALLBACK_1(World::OnContactBegin, _World);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

		return true;
	}
	else
	{
		return false;
	}
}

void GameSceneLayer::Update(float dT)
{
	_World->Update(dT);
}

void GameSceneLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

	World::Shutdown();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}