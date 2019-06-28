#include "StateMachine.h"

#include <typeinfo>
#include <iostream>
#include <string>

#include "LoadState.h"
#include "QuitState.h"
#include "PlayState.h"
#include "DeadState.h"
#include "MenuState.h"


StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
}

void StateMachine::init()
{
	pushState(std::make_unique<LoadState>(*this));
}

void StateMachine::pushState(std::unique_ptr<State> state)
{
	states_.push(std::move(state));

	printCurrentState();
}

void StateMachine::popState()
{
	states_.pop();
}

void StateMachine::update(float deltaTime)
{
	states_.top()->update(deltaTime);
}

void StateMachine::onInput(input_state_delta & input)
{
	states_.top()->onInput(input);
}

bool StateMachine::isStateQuit()
{
	return typeid(*states_.top()) == typeid(QuitState);
}

void StateMachine::printCurrentState()
{
	std::string name = typeid(*states_.top()).name();
	std::cout << name << std::endl;
}
