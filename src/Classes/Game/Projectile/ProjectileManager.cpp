#include "ProjectileManager.h"
#include "Projectile.h"
#include "Core/MemoryPool.h"
#include "Core/Utils.h"

ProjectileManager::ProjectileManager():
	m_ProjectilePool(64)
{
}

ProjectileManager::~ProjectileManager()
{
}

void ProjectileManager::CreateProjectile(ProjectileType projectileType, Vec2 position)
{
	Projectile* proj = nullptr;

	switch (projectileType)
	{
	case ProjectileType::BASIC_PLAYER:
		proj = m_ProjectilePool.Create("Images/laserBlue02.png", Vec2::UNIT_Y);
		break;
	}

	assert(proj != nullptr);

	proj->setPosition(position - getPosition());
	this->addChild(proj);
	m_Projectiles.push_back( proj );
}

void ProjectileManager::Update(float dT, const Vec2& playerPos)
{
	ParallaxElement::Update(playerPos);

	auto it = m_Projectiles.begin();
	while( it != m_Projectiles.end())
	{
		auto proj = (*it);
		proj->Update(dT);
		if (proj->ShouldBeDestroyed() )
		{
			this->removeChild(proj);
			m_ProjectilePool.Remove(proj);
			it = m_Projectiles.erase(it);
		}
		else
		{
			++it;
		}
	}
}

float ProjectileManager::GetParallaxWidth() const
{
	return Director::getInstance()->getWinSize().width * 1.2;
}

