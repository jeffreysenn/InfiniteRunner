#include "PlayerController.h"

#include "../Actors/AvatarActor.h"
#include "../Commands/CommandQueue.h"

void jumpAction(AvatarActor &avatarActor, float)
{
	avatarActor.jump();
}

void goStraightAction(AvatarActor &avatarActor, float)
{
	avatarActor.goStraight();
}

PlayerController::PlayerController()
{
	bindInputs();
	bindActions();
}

void PlayerController::handleEvent(const sf::Event & event, CommandQueue & commandQueue)
{
	for (auto &pair : mActionBinding)
	{
		const auto & gameInput = mInputBinding[pair.first];
		if ((!gameInput.bIsRealTime) &&
			Input::eventInputCollectionPressed(event, gameInput.inputCollection))
			commandQueue.push(pair.second);
	}
}

void PlayerController::handleRealtimeInput(CommandQueue &commandQueue)
{
	for (auto &pair : mActionBinding)
	{
		const auto & gameInput = mInputBinding[pair.first];
		if (gameInput.bIsRealTime &&
			Input::inputCollectionPressed(gameInput.inputCollection))
			commandQueue.push(pair.second);
	}
}

void PlayerController::bindInputs()
{
	mInputBinding[Action::Jump] =
	{
		{
			{Input::Type::Keyboard, sf::Keyboard::Space},
			{Input::Type::Keyboard, sf::Keyboard::W},
			{Input::Type::Keyboard, sf::Keyboard::Up}
		}, false
	};

	mInputBinding[Action::Down] =
	{
		{
			{Input::Type::Keyboard, sf::Keyboard::S},
			{Input::Type::Keyboard, sf::Keyboard::Down}
		}, false
	};
}

void PlayerController::bindActions()
{
	mActionBinding[Action::Jump].action = 
		derivedAction<AvatarActor>(jumpAction);

	mActionBinding[Action::Down].action =
		derivedAction<AvatarActor>(goStraightAction);

	for (auto &pair : mActionBinding)
		pair.second.category = Category::Avatar;
}

