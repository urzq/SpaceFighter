#include "Projectile.h"
#include "Game/GameObjectConst.h"

Projectile::Projectile(std::string spriteName, Vec2 direction, float speed):
	m_Direction(direction), 
	m_ToDestroy(false),
	m_Speed(speed)
{
	setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	m_Sprite = Sprite::create(spriteName);
	this->addChild(m_Sprite);

	auto body = PhysicsBody::createBox(Size(10, 30));
	body->setDynamic(true);
	
	body->setCategoryBitmask(0x00000002);
	body->setContactTestBitmask(0x00000001);

	this->setPhysicsBody(body);
	this->setTag((int)GameObjectConst::Tags::PROJECTILE);
}

Projectile::~Projectile()
{
	
}

void Projectile::Update(float dT)
{
	Vec2 pos = getPosition() + Vec2(0.0f, m_Speed);
	setPosition(pos);
}

bool Projectile::ShouldBeDestroyed() const
{
	if (m_ToDestroy)
	{
		return true;
	}

	auto screenHeight = Director::getInstance()->getWinSize().height;
	return getPosition().y > screenHeight;
}

void Projectile::Explode()
{
	m_ToDestroy = true;
}