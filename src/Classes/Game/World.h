#ifndef __WORLD_H__
#define __WORLD_H__

#include "cocos2d.h"

using namespace cocos2d;

namespace SpaceFighter
{
	class Player;
	class Background;
	class EnemyManager;
	class ProjectileManager;

	class World : public Node
	{
	private:
		World();
		~World();

	public:
		static void			Init();
		static void			Shutdown();
		static World&		GetInstance();

		void				Update(float dT);

		ProjectileManager&	GetProjectileManager() const;
		bool				OnContactBegin(PhysicsContact& contact);

	private:
		void				ProjectileCollideEnemy(Node* nodeProjectile, Node* nodeEnemy);

	private:
		Player*				_Player;
		Background*			_Background;
		EnemyManager*		_EnemyManager;
		ProjectileManager*	_ProjectileManager;

		static World*		_WorldInstance;
		static const float	_SCROLL_SPEED;
	};
}
#endif