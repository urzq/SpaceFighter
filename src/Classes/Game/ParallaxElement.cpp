#include "ParallaxElement.h"

void ParallaxElement::Update(const Vec2& playerPos)
{
	float elemWidth = GetParallaxWidth();
	float winWidth = Director::getInstance()->getWinSize().width;
	
	float leftBound = winWidth - elemWidth/2.0f;
	float rightBound = 0 + elemWidth/2.0f;
	float normalizedPlayerPos = playerPos.x / winWidth;

	float xPos = MathUtil::lerp(rightBound, leftBound, normalizedPlayerPos);

	setPosition( xPos, getPosition().y );
}