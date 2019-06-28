#pragma once
#include "State.h"
class QuitState :
	public State
{
public:
	QuitState(class StateMachine& stateMachine);
	~QuitState();
};

