#include "EnemyManager.h"
#include "math/MathUtil.h"
#include <algorithm>
#include <string>
#include <assert.h> 

#include "SimpleEnemy.h"

EnemyManager::EnemyManager()
{
	_Enemies.reserve(64);

	//Test -> this should come from a file
	CreateEnemy( "SimpleEnemy", Vec2(-200, 900));
	CreateEnemy( "SimpleEnemy", Vec2(0, 1000));
	CreateEnemy( "SimpleEnemy", Vec2(200, 1100));
}

EnemyManager::~EnemyManager()
{
}

const float EnemyManager::getLeftBound() const 
{
	//return 400;
	return 360;
}

const float EnemyManager::getRightBound() const
{
	//auto winSize = Director::getInstance()->getWinSize();
	//return winSize.width - _TopSprite->getContentSize().width/2;
	//return 240;
	return 280;
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

void EnemyManager::Update(const float dT, const float scrollSpeed, const float normalizedPosX, const Vec2& playerPos)
{
	ParallaxElement::Update(normalizedPosX);

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