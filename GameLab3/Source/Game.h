#pragma once

#include "Worlds/World.h"
#include "Debug/FPSMeter.h"
#include "Controllers/PlayerController.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
//#include "States/StateMachine.h"

class Game
{
public:
	Game();
	~Game();

	void run();

	void handleInputs();

	void update(float deltaSeconds);

	void render();

private:
	sf::RenderWindow mWindow;

	PlayerController mPlayerController;

	//StateMachine mStateMachine;

	World mWorld;

	sf::Font mFont;

	sf::Text mStatsText;
	FPSMeter mFPSMeter;

	bool mbPaused;
};

