#include "World.h"

const float World::_SCROLL_SPEED = 250;

World::World()
{
	_Player = new Player();
	this->addChild(_Player, 2);

	_Background = new Background();
	this->addChild(_Background, 0);

	_EnemyManager = new EnemyManager();
	this->addChild(_EnemyManager, 1);
}

World::~World()
{
	delete _Player;
	delete _Background;
	delete _EnemyManager;
}

void World::Update(float dT)
{
	_Player->Update(dT);
	_Background->Update(dT, _SCROLL_SPEED, _Player->getNormalizedPosX() );
	_EnemyManager->Update(dT, _SCROLL_SPEED, _Player->getNormalizedPosX(), _Player->getPosition() );
}