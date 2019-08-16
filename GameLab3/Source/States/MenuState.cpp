#include "MenuState.h"

#include "StateMachine.h"
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
}
