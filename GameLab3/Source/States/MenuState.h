#pragma once
#include "State.h"
#include "../Input/Input.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>

enum class Option
{
	Play,
	Settings,
	Credits,
	Exit,
	OptionCount,
};

static const char* OptionStrings[] =
{
	"Play",
	"Settings",
	"Credits",
	"Exit",
};

constexpr const char* getOptionText(const Option &option)
{
	return OptionStrings[static_cast<int>(option)];
}

//overload prefix ++
inline Option& operator++(Option &option)
{
	Option lastOption = static_cast<Option>(
		static_cast<int>(Option::OptionCount) - 1);
	return option = (option == lastOption) ? lastOption :
		static_cast<Option>(static_cast<int>(option) + 1);
}

//overload prefix --
inline Option& operator--(Option &option)
{
	Option firstOption = static_cast<Option>(0);
	return option = (option == firstOption) ? firstOption :
		static_cast<Option>(static_cast<int>(option) - 1);
}


class MenuState : public State
{
public:
	MenuState(StateStack &stateStack, const Context &context);
	~MenuState();

	virtual bool update(float deltaSeconds) override;
	virtual bool handleEvent(const sf::Event& event) override;
	virtual void draw() override;

private:
	void updateOptionText();

	void setupInputs();
	void setupBackgroundSprite();
	void setupOptions();

	void drawOptions();

private:
	sf::RenderWindow &mWindow;

	sf::Sprite mBackgroundSprite;

	typedef std::unique_ptr<sf::Text> TextPtr;
	std::map<Option, TextPtr> mOptionMap;
	Option mCurrentOption;
	
	Input::InputCollection mUpInputs;
	Input::InputCollection mDownInputs;
	Input::InputCollection mConfirmInputs;
};

