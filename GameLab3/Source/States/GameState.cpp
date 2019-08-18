#include "GameState.h"
#include "../Controllers/PlayerController.h"
#include "StateIdentifiers.h"

#include <SFML/Window/Event.hpp>

GameState::GameState(StateStack & stateStack, const Context & context)
	: State(stateStack, context)
	, mWorld(*context.window)
	, mPlayerController(*context.playerController)
{
}

GameState::~GameState()
{
}

bool GameState::update(float deltaSeconds)
{
	mWorld.update(deltaSeconds);
	mPlayerController.handleRealtimeInput(mWorld.getCommandQueue());
	return true;
}

void GameState::draw()
{
	mWorld.draw();
}

bool GameState::handleEvent(const sf::Event & event)
{
	mPlayerController.handleEvent(event, mWorld.getCommandQueue());

	if (event.type == sf::Event::KeyPressed 
		&& event.key.code == sf::Keyboard::Escape)
		requestStackPush(StateID::Pause);

	return true;
}
