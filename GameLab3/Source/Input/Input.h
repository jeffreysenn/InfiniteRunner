#pragma once

#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <vector>

namespace Input
{
	enum class InputType
	{
		Joystick,
		Keyboard,
		Mouse,
	};

	struct InputDatum
	{
		InputType inputType;

		union
		{
			uint32_t joystickButtonID;
			sf::Joystick::Axis joystickAxis;

			sf::Keyboard::Key keyboardKey;

			sf::Mouse::Button mouseButton;
		};
	};

	bool dataPressed(const std::vector<InputDatum> &inputData);

	bool datumPressed(const InputDatum &datum);
}

