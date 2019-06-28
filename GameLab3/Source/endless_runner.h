// endless_runner.h

#ifndef ENDLESS_RUNNER_H_INCLUDED
#define ENDLESS_RUNNER_H_INCLUDED

#include "Input/input_listener.h"
#include "Input/input_manager.h"
#include "ResourceManagers/ResourceManager.h"
#include "States/StateMachine.h"
#include "States/State.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

namespace Texture
{
	enum ID
	{
		Avatar,
		NONEXIST,
	};
}

struct endless_runner : input_listener
{
   endless_runner();

   bool init();
   void run();

private:
   void exit();

   // input listener interface
   bool on_input(input_state_delta &input) override;

private:
   sf::RenderWindow mWindow;
   input_manager input_manager_;

   ResourceManager<sf::Texture, Texture::ID> TextureManager;
   StateMachine stateMachine_;

};

#endif // ENDLESS_RUNNER_H_INCLUDED
