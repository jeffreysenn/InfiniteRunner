#include "LoadState.h"

#include "StateMachine.h"
#include "MenuState.h"

LoadState::LoadState(StateMachine& stateMachine)
	: State(stateMachine)
{
}


LoadState::~LoadState()
{
}

void LoadState::update(float deltaTime)
{
	stateMachine_.pushState(std::make_unique<MenuState>(stateMachine_));
}
