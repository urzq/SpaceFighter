#include "World.h"
#include "Player.h"
#include "Background.h"
#include "Enemy/EnemyManager.h"
#include "Enemy/BaseEnemy.h"
#include "Projectile/ProjectileManager.h"
#include "Game/Projectile/Projectile.h"
#include "Game/GameObjectConst.h"
#include "Core/Utils.h"
#include <assert.h>

using namespace SpaceFighter;

const float World::SCROLL_SPEED = 250;

World* World::_WorldInstance = nullptr;

void World::Init()
{
	assert(_WorldInstance == nullptr);
	_WorldInstance = new World();
}

void World::Shutdown()
{
	delete_safe(_WorldInstance);
}

World& World::GetInstance()
{
	assert(_WorldInstance != nullptr);
	return *_WorldInstance;
}

World::World():
	m_Player(std::make_unique<Player>()),
	m_Background(std::make_unique<Background>()),
	m_EnemyManager(std::make_unique<EnemyManager>()),
	m_ProjectileManager(std::make_unique<ProjectileManager>())
{
	this->addChild(m_Background.get(), 0);
	this->addChild(m_EnemyManager.get(), 1);
	this->addChild(m_ProjectileManager.get(), 2);
	this->addChild(m_Player.get(), 3);
}

World::~World()
{
}

Player& World::GetPlayer() const
{
	return *m_Player;
}

Background& World::GetBackground() const
{
	return *m_Background;
}

EnemyManager& World::GetEnemyManager() const
{
	return *m_EnemyManager;
}

ProjectileManager& World::GetProjectileManager() const
{
	return *m_ProjectileManager;
}

void World::ProjectileCollideEnemy(Node* nodeProjectile, Node* nodeEnemy)
{
	auto projectile = static_cast<Projectile*>(nodeProjectile);
	projectile->Explode();

	auto enemy = static_cast<BaseEnemy*>(nodeEnemy);
	enemy->Hurt(projectile->GetDommagePoint());
}

bool World::OnContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	auto tagA = nodeA->getTag();
	auto tagB = nodeB->getTag();

	if (tagA == (int)Tags::PROJECTILE && tagB == (int)Tags::ENEMY)
	{
		ProjectileCollideEnemy(nodeA, nodeB);
	}
	else if (tagA == (int)Tags::ENEMY && tagB == (int)Tags::PROJECTILE)
	{
		ProjectileCollideEnemy(nodeB, nodeA);
	}
	else
	{
		assert(false && "cannot handle this collision");
	}

	return false;
}