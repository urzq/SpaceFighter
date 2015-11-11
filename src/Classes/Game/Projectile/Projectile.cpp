#include "Projectile.h"

Projectile::Projectile(std::string spriteName, Vec2 direction) :
	m_Direction(direction)
{
	m_Sprite = Sprite::create(spriteName);
	this->addChild(m_Sprite);
}

Projectile::~Projectile()
{
	
}

void Projectile::Update(float dT)
{
	Vec2 pos = getPosition() + Vec2(0.0f, 10.0f);
	setPosition(pos);
}

bool Projectile::ShouldBeDestroyed() const
{
	auto screenHeight = Director::getInstance()->getWinSize().height;

	return getPosition().y > screenHeight;
}
