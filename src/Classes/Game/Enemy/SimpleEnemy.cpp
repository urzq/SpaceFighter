#include "SimpleEnemy.h"
#include "math/MathUtil.h"
#include <algorithm>

SimpleEnemy::SimpleEnemy(const Vec2& startPos): BaseEnemy(startPos)
{
	_Sprite = Sprite::create("Images/enemyRed1.png");
	this->addChild(_Sprite);
}

SimpleEnemy::~SimpleEnemy()
{
}
	
void SimpleEnemy::Update(const float dT, const Vec2& playerPos)
{
	setPosition( getPosition() - Vec2(0, 100 * dT) );
}

bool SimpleEnemy::ShouldBeDestroyed()
{
	return getPosition().y < 0;
}