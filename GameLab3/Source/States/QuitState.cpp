#include "QuitState.h"

#include "StateMachine.h"

QuitState::QuitState(StateMachine & stateMachine)
	:State(stateMachine)
{
}

QuitState::~QuitState()
{
}
