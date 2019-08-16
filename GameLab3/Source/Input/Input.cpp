#include "Input.h"

bool inputPressed(const Input::Input &input)
{
	switch (input.type)
	{
	// TODO: Implement Joystick index to support multiple joysticks
	case Input::Type::Joystick:
		return sf::Joystick::isButtonPressed(0, input.joystickButtonID);
		break;
	case Input::Type::Keyboard:
		return sf::Keyboard::isKeyPressed(input.keyboardKey);
		break;
	case Input::Type::Mouse:
		return sf::Mouse::isButtonPressed(input.mouseButton);
		break;
	default:
		break;
	}

	return false;
}

bool Input::inputCollectionPressed(const InputCollection &inputCollection)
{
	for (auto &input : inputCollection)
	{
		if (inputPressed(input))
			return true;
	}
	return false;
}

