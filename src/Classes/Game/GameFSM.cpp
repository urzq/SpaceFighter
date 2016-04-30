#include "GameFSM.h"
#include "World.h"
#include "Player.h"
#include "Background.h"
#include "Enemy/EnemyManager.h"
#include "Projectile/ProjectileManager.h"

using namespace SpaceFighter;

static const float SHIP_APPEAR_TIME = 1.2f;

GameFSM::GameFSM() :
CONSTRUCT_STATE(Intro),
CONSTRUCT_STATE(Game)
{
	ChangeState(Intro);
}

void GameFSM::OnIntroEnter()
{
	auto& world = World::GetInstance();

	world.GetPlayer().StartIntroAnimation(SHIP_APPEAR_TIME);

	m_Clock = 0;
}

void GameFSM::OnIntroUpdate(float dT)
{
	auto& world = World::GetInstance();
	const auto playerPos = world.GetPlayer().getPosition();

	world.GetBackground().Update(dT, World::SCROLL_SPEED, playerPos);

	m_Clock += dT;
	if (m_Clock > SHIP_APPEAR_TIME)
	{
		ChangeState(Game);
	}
}

void GameFSM::OnIntroExit()
{

}

void GameFSM::OnGameEnter()
{

}

void GameFSM::OnGameUpdate(float dT)
{
	auto& world = World::GetInstance();
	
	world.GetPlayer().Update(dT);
	const auto playerPos = world.GetPlayer().getPosition();

	world.GetBackground().Update(dT, World::SCROLL_SPEED, playerPos);
	world.GetEnemyManager().Update(dT, World::SCROLL_SPEED, playerPos);
	world.GetProjectileManager().Update(dT, playerPos);
}

void GameFSM::OnGameExit()
{

}

