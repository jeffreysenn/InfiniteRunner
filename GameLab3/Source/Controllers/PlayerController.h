#pragma once

#include "../Commands/Command.h"

namespace sf
{
	class Event;
}

class PlayerController
{
public:
	PlayerController();

	void handleEvent(const sf::Event& event, class CommandQueue& commandQueue);
	void handleRealtimeInput(class CommandQueue& commandqueue);

private:
	Command mCommand;
};

