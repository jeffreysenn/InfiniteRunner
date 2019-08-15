#include "PlayerController.h"

#include "../Actors/AvatarActor.h"
#include "../Input/InputBinding.h"
#include "../Commands/CommandQueue.h"

void jumpAction(AvatarActor &avatarActor, float)
{
	avatarActor.jump();
}

PlayerController::PlayerController()
{
	mCommand.action = derivedAction<AvatarActor>(jumpAction);
	mCommand.category = Category::Avatar;
}

void PlayerController::handleEvent(const sf::Event & event, CommandQueue & commandQueue)
{
}

void PlayerController::handleRealtimeInput(CommandQueue &commandqueue)
{
	if (Input::dataPressed(InputBinding::Jump))
	{
		commandqueue.push(mCommand);
	}
}

