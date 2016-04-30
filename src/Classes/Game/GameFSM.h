#ifndef __GAME_FSM_H__
#define __GAME_FSM_H__

#include "cocos2d.h"
#include "Core/FSM.h"

using namespace cocos2d;
using namespace Core;

namespace SpaceFighter
{
	class World;

	class GameFSM : public FSM
	{
	public:
		GameFSM();

	private:
		float m_Clock = 0;

	private:
		DECL_STATE(Intro);
		DECL_STATE(Game);
	};
}
#endif