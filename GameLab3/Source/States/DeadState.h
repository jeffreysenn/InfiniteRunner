#pragma once
#include "State.h"
class DeadState :
	public State
{
public:
	DeadState(class StateMachine& stateMachine);
	~DeadState();
};

