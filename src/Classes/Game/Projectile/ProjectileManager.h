#ifndef __PROJECTILE_MANAGER_H__
#define __PROJECTILE_MANAGER_H__

#include "cocos2d.h"
#include "Core/MemoryPool.h"
#include "Game/ParallaxElement.h"
#include <vector>

USING_NS_CC;

class Projectile;

enum class ProjectileType
{
	BASIC_PLAYER = 0,
};

class ProjectileManager : public ParallaxElement
{
public:
	ProjectileManager();
	~ProjectileManager();
	
	void Update(float dT, const Vec2& playerPos);
	void CreateProjectile(ProjectileType projectileType, Vec2 position);

	float GetParallaxWidth() const override;

private:
	MemoryPool<Projectile> m_ProjectilePool;
	std::vector<Projectile*> m_Projectiles; //is it the right data structure ? we are inserting and removing a lot, so maybe a list is better.
};

#endif //__PROJECTILE_MANAGER_H__