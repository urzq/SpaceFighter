#include "BaseEnemy.h"
#include "Game/GameObjectConst.h"

using namespace SpaceFighter;

BaseEnemy::BaseEnemy(const Vec2& startPos, const Size& size, int hp):
	m_Hp(hp), 
	m_ToDestroy(false)
{
	setPosition(startPos);
	setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	auto body = PhysicsBody::createBox(size);
	body->setDynamic(true);
	body->setCategoryBitmask(0x00000001);
	body->setContactTestBitmask(0x00000002);

	this->setPhysicsBody(body);
	this->setTag((int)SpaceFighter::Tags::ENEMY);
}

BaseEnemy::~BaseEnemy()
{
}

void BaseEnemy::Hurt(int dmg)
{
	m_Hp--;
	if (m_Hp <= 0)
	{
		m_ToDestroy = true;
	}
}