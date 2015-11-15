#ifndef __BASE_ENEMY_
#define __BASE_ENEMY_

#include "cocos2d.h"

USING_NS_CC;

class BaseEnemy: public Node
{
public:
	BaseEnemy(const Vec2& startPos, const Size& size, int hp);
	virtual ~BaseEnemy();
	
	virtual void Update(const float dT, const Vec2& playerPos) = 0;
	virtual bool ShouldBeDestroyed() = 0;
	void Hurt(int dmg);

protected:
	Sprite* m_Sprite;
	int		m_Hp;
	bool	m_ToDestroy;
};

#endif