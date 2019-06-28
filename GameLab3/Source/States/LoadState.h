#pragma once
#include "State.h"

class LoadState :
	public State
{
public:
	LoadState(class StateMachine& stateMachine);
	~LoadState();

	void update(float deltaTime) override;
};

