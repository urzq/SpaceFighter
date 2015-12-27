#ifndef __PARALLAX_ELEMENT_H__
#define __PARALLAX_ELEMENT_H__

#include "cocos2d.h"

using namespace cocos2d;

namespace SpaceFighter
{
	//moves the node on the x axis, depending on where the player's ship is.
	class ParallaxElement : public Node
	{
	public:
		virtual float GetParallaxWidth() const = 0;

		void Update(const Vec2& playerPos);
	};
}

#endif