#include "Player.h"
#include "World.h"
#include "Projectile\ProjectileManager.h"
#include <algorithm>

using namespace cocos2d;
using namespace SpaceFighter;

const float Player::_SHOOT_FREQUENCY = 4.0f;

Player::Player():
	_Clock(0.0f)
{
	_Sprite = Sprite::create("Images/playerShip2_blue.png");
	this->addChild(_Sprite);

	auto screenSize = Director::getInstance()->getWinSize();
	auto pos = Vec2( (screenSize.width/2)*1, 50);
    this->setPosition(pos) ;
	_Destination = pos;

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Player::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Player::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Player::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

Player::~Player()
{
	this->removeAllChildren();
}
		
bool Player::onTouchBegan(Touch* touch, Event* event)
{
	 _Destination = touch->getLocation();
	 return true;
}

void Player::onTouchMoved(Touch* touch, Event* event)
{
	_Destination = touch->getLocation();
}

void Player::onTouchEnded(Touch* touch, Event* event)
{
	_Destination = this->getPosition();
}

void Player::Update(float dT)
{
	_UpdatePosition(dT);	
	_UpdateProjectile(dT);
}

void Player::_UpdatePosition(float dT)
{
	// Moves the ship
	auto pos = getPosition();
	auto dir = _Destination - pos;
	auto len = dir.length();
	dir.normalize();
	auto offset = std::min(len, dT * SHIP_SPEED);

	pos = pos + dir * offset;

	// And constraint its position without the world
	auto halfShip = _Sprite->getContentSize() / 2;
	pos = pos.getClampPoint( halfShip, Director::getInstance()->getWinSize()-halfShip);

	setPosition(pos);
}

void Player::_UpdateProjectile(float dT)
{
	_Clock += dT;
	auto shootPeriod = 1.f / _SHOOT_FREQUENCY;

	if ( _Clock > shootPeriod )
	{
		_Clock -= shootPeriod;
		auto& projMgr = World::GetInstance().GetProjectileManager();

		Vec2 pos = getPosition() + Vec2(0.0f, 30.0f);
		projMgr.CreateProjectile(ProjectileType::BASIC_PLAYER, pos);

	}
}