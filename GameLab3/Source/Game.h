#pragma once

#include "Worlds/World.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
//#include "States/StateMachine.h"

class Game
{
public:
	Game();
	~Game();

	void run();

	void handleEvents();

	void update(float deltaSeconds);

	void render();

private:
	sf::RenderWindow mWindow;

	//StateMachine mStateMachine;

	World mWorld;

	sf::Font mFont;

	sf::Text mStatsText;

	bool mBPaused;
};

