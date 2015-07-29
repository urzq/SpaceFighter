#ifndef __WORLD_H__
#define __WORLD__

#include "cocos2d.h"
#include "Player.h"
#include "Background.h"

USING_NS_CC;

class World: public Node
{
public:
	World();
	~World();
	
	void Update(float dT);

private:
	Player* _Player;
	Background* _Background;

	static const float _SCROLL_SPEED;
};

#endif