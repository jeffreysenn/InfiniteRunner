#include "Input.h"

bool Input::datumPressed(const InputDatum &datum)
{
	switch (datum.inputType)
	{
	// TODO: Implement Joystick index to support multiple joysticks
	case InputType::Joystick:
		return sf::Joystick::isButtonPressed(0, datum.joystickButtonID);
		break;
	case InputType::Keyboard:
		return sf::Keyboard::isKeyPressed(datum.keyboardKey);
		break;
	case InputType::Mouse:
		return sf::Mouse::isButtonPressed(datum.mouseButton);
		break;
	default:
		break;
	}

	return false;
}

bool Input::dataPressed(const std::vector<InputDatum> &inputData)
{
	for (auto &inputDatum : inputData)
	{
		if (datumPressed(inputDatum))
			return true;
	}
	return false;
}
