// endless_runner.h

#ifndef ENDLESS_RUNNER_H_INCLUDED
#define ENDLESS_RUNNER_H_INCLUDED

#include "Input/input_listener.h"

#include "Input/input_manager.h"
#include "ResourceManagers/ResourceIdentifiers.h"
#include "States/StateMachine.h"
#include "States/State.h"
#include "Worlds/World.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>



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

   TextureManager mTextureManager;
   StateMachine stateMachine_;
   World mWorld;
};

#endif // ENDLESS_RUNNER_H_INCLUDED
