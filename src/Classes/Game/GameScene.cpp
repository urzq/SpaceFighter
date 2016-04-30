#include "GameScene.h"

#include "World.h"
#include "GameFSM.h"
#include "Core/Utils.h"

using namespace cocos2d;
using namespace SpaceFighter;

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2::ZERO);

    auto layer = GameSceneLayer::create();
    scene->addChild(layer);

    return scene;
}

bool GameSceneLayer::init()
{
	if (Layer::init())
	{
		World::Init();
		this->addChild(&World::GetInstance());

		m_GameFSM = new GameFSM();

		schedule(CC_SCHEDULE_SELECTOR(GameSceneLayer::Update));

		auto contactListener = EventListenerPhysicsContact::create();

		contactListener->onContactBegin = CC_CALLBACK_1(World::OnContactBegin, &World::GetInstance());
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
	m_GameFSM->Update(dT);
}

void GameSceneLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

	World::Shutdown();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

	delete_safe(m_GameFSM);
}