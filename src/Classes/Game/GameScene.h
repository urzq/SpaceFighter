#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <memory.h>
#include "cocos2d.h"

namespace SpaceFighter
{
	class GameScene : public cocos2d::Scene
	{
	public:
		static cocos2d::Scene* createScene();
	};

	class World;
	class GameFSM;

	class GameSceneLayer : public cocos2d::Layer
	{
	public:
		CREATE_FUNC(GameSceneLayer);

		virtual bool init();

		void menuCloseCallback(cocos2d::Ref* pSender);
		void Update(float dT);

	private:
		GameFSM* m_GameFSM;
	};
}
#endif // __MAIN_SCENE_H__
