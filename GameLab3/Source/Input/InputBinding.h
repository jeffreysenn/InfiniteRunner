#pragma once

#include "Input.h"

#include <vector>

namespace InputBinding
{
	static const std::vector<Input::InputDatum> Jump
	{
		{Input::InputType::Keyboard, sf::Keyboard::Space},
		{Input::InputType::Keyboard, sf::Keyboard::W},
		{Input::InputType::Keyboard, sf::Keyboard::Up}
	};

	static const std::vector<Input::InputDatum> Down
	{
		{Input::InputType::Keyboard, sf::Keyboard::S},
		{Input::InputType::Keyboard, sf::Keyboard::Down}
	};

}
