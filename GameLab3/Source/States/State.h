#pragma once
class State
{
public:
	State(class StateMachine& stateMachine);

	virtual ~State() = default;

	virtual void update(float deltaSeconds) {}

	virtual void onInput(struct input_state_delta &input);

protected:
	class StateMachine& stateMachine_;

};

