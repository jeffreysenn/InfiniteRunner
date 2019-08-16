#pragma once

#include "../Commands/Command.h"
#include "../Input/Input.h"

#include <map>
#include <vector>

namespace sf
{
	class Event;
}

enum class Action
{
	Jump,
	Down
};

class PlayerController
{
public:
	PlayerController();

	void handleEvent(const sf::Event& event, class CommandQueue& commandQueue);
	void handleRealtimeInput(class CommandQueue& commandqueue);

private:
	void bindInputs();
	void bindActions();

private:
	Command mCommand;

	std::map<Action, Input::InputCollection> mInputBinding;
	std::map<Action, Command> mActionBinding;
};

