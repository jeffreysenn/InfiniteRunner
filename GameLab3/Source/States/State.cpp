#include "State.h"

#include "StateIdentifiers.h"
#include "StateStack.h"

State::Context::Context(
	sf::RenderWindow & window, TextureManager & textureManager, 
	FontManager & fontManager, PlayerController & playerController)
	: window(&window)
	, textureManager(&textureManager)
	, fontManager(&fontManager)
	, playerController(&playerController)
{
}

State::State(StateStack & stack, const Context &context)
	: mStack(stack)
	, mContext(context)
	, mWindow(*context.window)
{
}

State::~State()
{
}

void State::requestStackPush(StateID stateID)
{
	mStack.pushState(stateID);
}

void State::requestStackPop()
{
	mStack.popState();
}

void State::requestStateClear()
{
	mStack.clearStates();
}