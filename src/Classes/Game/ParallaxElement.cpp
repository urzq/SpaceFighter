#include "ParallaxElement.h"

void ParallaxElement::Update(const float normalizedPosX)
{
	auto leftBound = getLeftBound();
	auto rightBound = getRightBound();
	auto xPos = MathUtil::lerp(leftBound, rightBound, normalizedPosX);

	setPosition( xPos, getPosition().y );
}