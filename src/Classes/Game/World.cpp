#include "World.h"

const float World::_SCROLL_SPEED = 250;

World::World()
{
	_Player = new Player();
	this->addChild(_Player, 1);

	_Background = new Background();
	this->addChild(_Background, 0);
}

World::~World()
{
	delete _Player;
	delete _Background;
}

void World::Update(float dT)
{
	_Player->Update(dT);
	_Background->Update(dT, _SCROLL_SPEED, _Player->getNormalizedPosX() );
}