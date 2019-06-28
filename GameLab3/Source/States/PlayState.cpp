#include "PlayState.h"

#include "StateMachine.h"

PlayState::PlayState(StateMachine & stateMachine)
	:State(stateMachine)
{
}

PlayState::~PlayState()
{
}
