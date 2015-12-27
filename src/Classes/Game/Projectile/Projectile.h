#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "cocos2d.h"

USING_NS_CC;

namespace SpaceFighter
{
	class Projectile : public Node
	{
	public:
		Projectile(std::string spriteName, Vec2 direction, float speed);
		~Projectile();

		//return true if this projectile needs to be destroyed.
		void Update(float dT);
		bool ShouldBeDestroyed() const;
		void Explode();
		int GetDommagePoint() { return 1; }

	private:
		Vec2 m_Direction;
		Sprite* m_Sprite;
		bool m_ToDestroy;
		const float m_Speed;

	};
}

#endif //__PROJECTILE_H__