#ifndef __BACKGROUND_H__
#define __BACKGROUND__

#include "cocos2d.h"
#include "ParallaxElement.h"

USING_NS_CC;

class Background: public ParallaxElement
{
public:
	Background();
	~Background();
	
	// param scrollSpeed: pixel/sec
	void Background::Update(const float dT, const float scrollSpeed, const float normalizedPosX);

	virtual const float getLeftBound() const override;
	virtual const float getRightBound() const override;

private:
	Sprite* _TopSprite;
	Sprite* _BotSprite;

	Sprite* _CreateSprite(const Vec2& spritePos);
};

#endif