#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "World.h"

namespace SpaceFighter
{
	class GameScene : public cocos2d::Scene
	{
	public:
		// there's no 'id' in cpp, so we recommend returning the class instance pointer
		static cocos2d::Scene* createScene();
	};

	class GameSceneLayer : public cocos2d::Layer
	{
	public:
		// implement the "static create()" method manually
		CREATE_FUNC(GameSceneLayer);

		// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
		virtual bool init();

		// a selector callback
		void menuCloseCallback(cocos2d::Ref* pSender);
		void Update(float dT);

	private:
		World* _World;
	};
}
#endif // __MAIN_SCENE_H__
