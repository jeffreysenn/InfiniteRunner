#pragma once

#include "../Commands/Command.h"
#include "../Input/Input.h"

#include <map>
#include <vector>

namespace sf
{
	class Event;
}



class PlayerController
{
public:
	PlayerController();

	void handleEvent(const sf::Event& event, class CommandQueue& commandQueue);
	void handleRealtimeInput(class CommandQueue& commandQueue);

private:
	enum class Action
	{
		Jump,
		Down
	};

	struct GameInput
	{
		Input::InputCollection inputCollection;
		bool bIsRealTime;
	};

private:
	void bindInputs();
	void bindActions();

private:
	Command mCommand;

	std::map<Action, GameInput> mInputBinding;
	std::map<Action, Command> mActionBinding;
};

