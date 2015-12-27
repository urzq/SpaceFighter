#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

using namespace cocos2d;

const int SHIP_SPEED = 800;

namespace SpaceFighter
{
	class Player : public Node
	{
	public:
		Player();
		~Player();

		void Update(float dT);

	private:
		void _UpdatePosition(float dT);
		void _UpdateProjectile(float dT);

	private:
		Sprite* _Sprite;
		Vec2 _Destination;
		float _Clock;

		static const float _SHOOT_FREQUENCY;

		bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
		void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
		void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	};
}
#endif