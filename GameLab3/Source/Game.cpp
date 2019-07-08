#include "Game.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>  

const sf::Time updateInterval = sf::seconds(1.f / 60.f);
const sf::Time statsUpdateInterval = sf::seconds(.5f);

Game::Game()
	: mWindow(
	sf::VideoMode(1920, 1080),
	"Endless Runner",
	sf::Style::Titlebar | sf::Style::Close)
	, mWorld(mWindow)
	, mBPaused(false)
{
	mWindow.setKeyRepeatEnabled(true);

	mFont.loadFromFile("Assets/Fonts/Minecraft.ttf");
	mStatsText.setFont(mFont);
	mStatsText.setCharacterSize(20);
	mStatsText.setPosition(10, 10);
	mStatsText.setFillColor(sf::Color::Magenta);
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Time timeSinceLastStatsUpdate = sf::Time::Zero;
	uint32_t statsFrameCount = 0;

	while (mWindow.isOpen())
	{
		sf::Time lastLoopDuration = clock.restart();
		timeSinceLastUpdate += lastLoopDuration;

		// Fix the update interval. 
		// In case render takes longer than TimePerFrame
		while (timeSinceLastUpdate > updateInterval)
		{
			timeSinceLastUpdate -= updateInterval;
			handleEvents();
			update(updateInterval.asSeconds());
		}

		// Update states
		statsFrameCount++;
		timeSinceLastStatsUpdate += lastLoopDuration;
		while (timeSinceLastStatsUpdate > statsUpdateInterval)
		{
			uint32_t fps = (uint32_t)(statsFrameCount / statsUpdateInterval.asSeconds());
			uint32_t ft = (uint32_t)(timeSinceLastStatsUpdate.asMicroseconds() / statsFrameCount);
			mStatsText.setString("FPS : " + std::to_string(fps) + "\n" +
								 "FT : " + std::to_string(ft) + " us");

			timeSinceLastStatsUpdate -= statsUpdateInterval;
			statsFrameCount = 0;
		}

		render();
	}
}

void Game::handleEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		// Closing window events
		if (event.type == sf::Event::Closed)
			mWindow.close();
		
		if (event.type == sf::Event::KeyPressed
			&& event.key.code == sf::Keyboard::Escape)
			mWindow.close();

		// Focus events
		if (event.type == sf::Event::LostFocus)
			mBPaused = true;
		else if (event.type == sf::Event::GainedFocus)
			mBPaused = false;
	}
}

void Game::update(float deltaSeconds)
{
	if (mBPaused)
		return;
	mWorld.update(deltaSeconds);
}

void Game::render()
{
	mWindow.clear();

	mWorld.draw();

	// Move to default view so that stats can be drawn at the right position
	mWindow.setView(mWindow.getDefaultView());
	// Draw stats
	mWindow.draw(mStatsText);

	mWindow.display();
}
