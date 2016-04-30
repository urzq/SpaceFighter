#include "EnemyManager.h"
#include "math/MathUtil.h"
#include <algorithm>
#include <string>
#include <assert.h> 

#include "SimpleEnemy.h"

using namespace SpaceFighter;

EnemyManager::EnemyManager()
{
	_Enemies.reserve(64);

	//Test -> this should come from a file
	CreateEnemy( "SimpleEnemy", Vec2(-200, 1000));
	CreateEnemy( "SimpleEnemy", Vec2(0, 1100));
	CreateEnemy( "SimpleEnemy", Vec2(200, 1200));
}

EnemyManager::~EnemyManager()
{
}

float EnemyManager::GetParallaxWidth() const
{
	return Director::getInstance()->getWinSize().width * 1.2;
}

BaseEnemy* EnemyManager::CreateEnemy( const std::string& ennemyType, const Vec2& startPos)
{
	BaseEnemy* enemy = nullptr;

	if(ennemyType == "SimpleEnemy")
	{
		enemy = new SimpleEnemy(startPos);
	}

	assert(enemy && "Cannot handle ennemyType");
	
	this->addChild(enemy);
	_Enemies.push_back(enemy);
	return enemy;
}

void EnemyManager::Update(const float dT, const float scrollSpeed, const Vec2& playerPos)
{
	ParallaxElement::Update(playerPos);

	for ( auto it = _Enemies.begin(); it != _Enemies.end(); )
	{
		auto enemy = (*it);
		enemy->Update(dT, playerPos);

		if( enemy->ShouldBeDestroyed() )
		{
			this->removeChild(enemy);
			it = _Enemies.erase(it);
			delete enemy;
		}
		else
		{
			++it;
		}
	}

}