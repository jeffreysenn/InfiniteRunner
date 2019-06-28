#include "MenuState.h"

#include "StateMachine.h"
#include "../Input/InputCode.h"
#include "../Input/input_state_delta.h"
#include "PlayState.h"

MenuState::MenuState(StateMachine & stateMachine)
	:State(stateMachine)
{
}

MenuState::~MenuState()
{
}

void MenuState::onInput(input_state_delta & input)
{
	State::onInput(input);

	if (input.has_action(InputCode::PLAY_CODE))
	{
		stateMachine_.pushState(std::make_unique<PlayState>(stateMachine_));
	}
}
