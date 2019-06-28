#include "State.h"

#include "StateMachine.h"
#include "QuitState.h"
#include "../Input/input_state_delta.h"
#include "../Input/InputCode.h"

State::State(StateMachine & stateMachine)
	:stateMachine_(stateMachine)
{
}

void State::onInput(input_state_delta & input)
{
	if (input.has_action(InputCode::EXIT_CODE))
	{
		stateMachine_.pushState(std::make_unique<QuitState>(stateMachine_));
		input.eat_action(InputCode::EXIT_CODE);
	}
}
