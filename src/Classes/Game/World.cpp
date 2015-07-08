#include "World.h"

World::World()
{
	_Player = new Player();
	this->addChild(_Player);
}

World::~World()
{
	delete _Player;
}

void World::Update(float dT)
{
	_Player->Update(dT);
}