#pragma once
#include "State.h"


class MenuState :
	public State
{
public:
	MenuState(class StateMachine& stateMachine);
	~MenuState();

	void onInput(struct input_state_delta &input) override;
};

