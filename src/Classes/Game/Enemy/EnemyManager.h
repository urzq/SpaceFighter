#ifndef __ENEMY_MANAGER_H__
#define __ENEMY_MANAGER_H__

#include <vector>

#include "cocos2d.h"
#include "../ParallaxElement.h"
#include "BaseEnemy.h"

USING_NS_CC;

class EnemyManager: public ParallaxElement
{
public:
	EnemyManager();
	~EnemyManager();
	
	// param scrollSpeed: pixel/sec
	void Update(const float dT, const float scrollSpeed, const Vec2& playerPos);

	float GetParallaxWidth() const override;

	BaseEnemy* CreateEnemy( const std::string& ennemyType, const Vec2& startPos);

private:
	std::vector<BaseEnemy*> _Enemies;
};

#endif