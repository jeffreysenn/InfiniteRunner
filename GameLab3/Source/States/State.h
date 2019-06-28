#pragma once
class State
{
public:
	State(class StateMachine& stateMachine);

	virtual ~State() = default;

	virtual void update(float deltaTime) {}

	virtual void onInput(struct input_state_delta &input);

protected:
	class StateMachine& stateMachine_;

};

