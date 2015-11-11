#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "cocos2d.h"

USING_NS_CC;

class Projectile: public Node
{
public:
	Projectile(std::string spriteName, Vec2 direction);
	~Projectile();
	
	//return true if this projectile needs to be destroyed.
	void Update(float dT);
	bool ShouldBeDestroyed() const;

private:
	Vec2 m_Direction;
	Sprite* m_Sprite;
};

#endif //__PROJECTILE_H__