#ifndef __WORLD_H__
#define __WORLD__

#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

class World: public Node
{
public:
	World();
	~World();
	
	void Update(float dT);

private:
	Player* _Player;
};

#endif