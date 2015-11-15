#include "SimpleEnemy.h"
#include "math/MathUtil.h"
#include <algorithm>

SimpleEnemy::SimpleEnemy(const Vec2& startPos) : 
	BaseEnemy(startPos, Size(60, 40), 4)
{
	m_Sprite = Sprite::create("Images/enemyRed1.png");
	this->addChild(m_Sprite);
}

SimpleEnemy::~SimpleEnemy()
{
	this->removeAllChildren();
}
	
void SimpleEnemy::Update(const float dT, const Vec2& playerPos)
{
	setPosition( getPosition() - Vec2(0, 100 * dT) );
}

bool SimpleEnemy::ShouldBeDestroyed()
{
	return m_ToDestroy || getPosition().y < 0;
}