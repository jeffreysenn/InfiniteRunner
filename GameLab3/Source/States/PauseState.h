#pragma once
#include "State.h"

#include <SFML/Window/Event.hpp>

class PauseState :
	public State
{
public:
	PauseState(StateStack &stateStack, const Context &context);
	~PauseState();

	virtual bool update(float deltaSeconds) override;
	virtual bool handleEvent(const sf::Event& event) override;
};

