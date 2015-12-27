#ifndef _FSM_H_
#define _FSM_H_

#include <functional>

#define DECL_STATE(state)\
State state;\
void On##state##Enter();\
void On##state##Update(float delta);\
void On##state##Exit();\

#define	CONSTRUCT_STATE(state)\
state(\
	[this](){this->On##state##Enter(); },\
	[this](float dT){this->On##state##Update(dT); },\
	[this](){this->On##state##Exit();}\
)

class State
{
public:
	
	State(std::function<void(void)> enter, std::function<void(float)> update, std::function<void(void)> exit):
		m_Enter(enter),
		m_Update(update),
		m_Exit(exit)
	{
	}

	std::function<void(void)> m_Enter;
	std::function<void(float)> m_Update;
	std::function<void(void)> m_Exit;
};

class FSM
{
public:
	FSM() : m_CurrentState(nullptr)
	{
	}

	void ChangeState(State &state)
	{
		if (m_CurrentState)
		{
			m_CurrentState->m_Exit();
		}

		m_CurrentState = &state;

		m_CurrentState->m_Enter();
	}

	void Update(float delta)
	{
		if (m_CurrentState)
		{
			m_CurrentState->m_Update(delta);
		}
	}

private:
	State* m_CurrentState;

};

#endif

