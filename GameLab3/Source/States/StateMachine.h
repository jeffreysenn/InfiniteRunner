#pragma once

#include <memory>
#include <stack>

#include "State.h"

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void init();

	void pushState(std::unique_ptr<State> state);
	void popState();

	void update(float deltaSeconds);

	void onInput(struct input_state_delta &input);

	bool isStateQuit();

	void printCurrentState();


protected:

private:
	std::stack<std::unique_ptr<State>> states_;

};

