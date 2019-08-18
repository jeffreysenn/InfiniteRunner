#include "PauseState.h"



PauseState::PauseState(StateStack & stateStack, const Context & context)
	: State(stateStack, context)
{
}


PauseState::~PauseState()
{
}

bool PauseState::update(float deltaSeconds)
{
	return false;
}

bool PauseState::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed
		&& event.key.code == sf::Keyboard::Escape)
		requestStackPop();

	return false;
}
