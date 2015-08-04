#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

USING_NS_CC;

const int SHIP_SPEED = 800;

class Player: public Node
{
public:
	Player();
	~Player();
	
	void Update(float dT);

private:
	Sprite* _Sprite;
	Vec2 _Destination;

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif