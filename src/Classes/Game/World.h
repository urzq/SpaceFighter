#ifndef __WORLD_H__
#define __WORLD_H__

#include "cocos2d.h"
#include <memory.h>

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

		Player&				GetPlayer() const;
		Background&			GetBackground() const;
		EnemyManager&		GetEnemyManager() const;
		ProjectileManager&	GetProjectileManager() const;

		bool				OnContactBegin(PhysicsContact& contact);
	
	public:
		static const float	SCROLL_SPEED;

	private:
		void				ProjectileCollideEnemy(Node* nodeProjectile, Node* nodeEnemy);

	private:
		std::unique_ptr<Player>				m_Player;
		std::unique_ptr<Background>			m_Background;
		std::unique_ptr<EnemyManager>		m_EnemyManager;
		std::unique_ptr<ProjectileManager>	m_ProjectileManager;

		static World*		_WorldInstance;
	};
}
#endif