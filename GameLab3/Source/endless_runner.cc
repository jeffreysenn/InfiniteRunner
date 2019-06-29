// endless_runner.cc

#include "endless_runner.h"

#include <iostream>
#include <typeinfo>

#include "Input/input_context.h"
#include "Input/InputCode.h"
#include "States/LoadState.h"
#include "States/QuitState.h"


template <typename T> T min(T a, T b) { return a < b ? a : b; }

static float get_deltatime(sf::Clock &clock)
{
	sf::Time diff = clock.restart();
	float dt = min(diff.asSeconds(), 1.0f / 60.0f);
	return dt;
}

endless_runner::endless_runner()
	: mWindow(sf::VideoMode(1280, 720), "endless-runner", sf::Style::Titlebar | sf::Style::Close)
	, input_manager_(mWindow)
	, mWorld(mWindow)
{
}

bool endless_runner::init()
{
	// note: disable key repeats
	mWindow.setKeyRepeatEnabled(false);

	// note: enable vertical sync
	mWindow.setVerticalSyncEnabled(true);

	// note: initialize state machine
	stateMachine_.init();

	// note: base input context for global game
	auto context = input_manager_.create_context("base");

	// note: bind an action to the newly created input context
	//       when we press escape we will set the current 
	//       state to be GAME_STATE_QUIT which makes the 
	//       game exit
	context->bind_action(sf::Keyboard::Escape, InputCode::EXIT_CODE);
	context->bind_action(sf::Keyboard::Space, InputCode::PLAY_CODE);

	// note: push base context to input stack
	input_manager_.push_context("base");

	// note: register 'this' to receive input
	input_manager_.attach_listener(this);

	// note: preload textures

	// note: preload sound buffers

	// note: preload fonts

	return true;
}

void endless_runner::run()
{
	sf::Clock clock;
	while (mWindow.isOpen())
	{
		// note: calculate delta time
		float deltatime = get_deltatime(clock);

		// note: quite the loop if state is quit
		if (stateMachine_.isStateQuit()) { break; }

		// note: the input manager handles the polling of 
		//       all sf::Events and dispatching the changes
		//       in input actions and states to all listeners
		if (!input_manager_.process())
			break;

		stateMachine_.update(0.f);
		mWorld.update(deltatime);

		// note: here we will eventually draw sprites et al.
		mWindow.clear();

		mWorld.draw();

		mWindow.display();
	}

	exit();
}

void endless_runner::exit()
{
	mWindow.close();
}

// input_listener
bool endless_runner::on_input(input_state_delta &input)
{
	stateMachine_.onInput(input);

	return true;
}
