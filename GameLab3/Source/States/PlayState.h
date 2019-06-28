#pragma once
#include "State.h"
class PlayState :
	public State
{
public:
	PlayState(class StateMachine& stateMachine);
	~PlayState();
};

