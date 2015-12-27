#ifndef __BACKGROUND_H__
#define __BACKGROUND__

#include "cocos2d.h"
#include "ParallaxElement.h"

using namespace cocos2d;

namespace SpaceFighter
{
	class Background : public ParallaxElement
	{
	public:
		Background();
		~Background();

		// param scrollSpeed: pixel/sec
		void Background::Update(const float dT, const float scrollSpeed, const Vec2& playerPos);

		virtual float GetParallaxWidth() const override;

	private:
		Sprite* _TopSprite;
		Sprite* _BotSprite;

		Sprite* _CreateSprite(const Vec2& spritePos);
	};
}

#endif