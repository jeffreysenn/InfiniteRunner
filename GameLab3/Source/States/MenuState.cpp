#include "MenuState.h"
#include "../Helpers/GraphicsHelper.h"
#include "StateIdentifiers.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>


MenuState::MenuState(StateStack & stateStack, const Context & context)
	: State(stateStack, context)
	, mWindow(*context.window)
	, mCurrentOption(static_cast<Option>(0))
{
	setupInputs();
	setupBackgroundSprite();
	setupOptions();
}


MenuState::~MenuState()
{
}

bool MenuState::update(float deltaSeconds)
{
	return false;
}

bool MenuState::handleEvent(const sf::Event & event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (Input::eventInputCollectionPressed(event, mConfirmInputs))
	{
		switch (mCurrentOption)
		{
		case Option::Play:
			requestStackPop();
			requestStackPush(StateID::Game);
			break;
		case Option::Settings:
			break;
		case Option::Credits:
			break;
		case Option::Exit:
			requestStackPop();
			break;
		default:
			break;
		}
	}

	if (Input::eventInputCollectionPressed(event, mUpInputs))
		--mCurrentOption;
	if (Input::eventInputCollectionPressed(event, mDownInputs))
		++mCurrentOption;

	updateOptionText();
	return false;
}

void MenuState::draw()
{
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mBackgroundSprite);
	drawOptions();
}

void MenuState::setupInputs()
{
	mUpInputs = 
	{
		{Input::Type::Keyboard, sf::Keyboard::W}, 
		{Input::Type::Keyboard, sf::Keyboard::Up}
	};

	mDownInputs =
	{
		{Input::Type::Keyboard, sf::Keyboard::S},
		{Input::Type::Keyboard, sf::Keyboard::Down}
	};

	mConfirmInputs = 
	{
		{Input::Type::Keyboard, sf::Keyboard::Enter},
		{Input::Type::Keyboard, sf::Keyboard::Space}
	};
}

void MenuState::setupBackgroundSprite()
{
	 //TODO: load resources in loadingState
	getContext().textureManager->
		load(Texture::Back,
			 "Assets/sunny-land-files/environment/back.png");

	auto & backgroungTexture = *getContext().textureManager->get(Texture::Back);
	backgroungTexture.setRepeated(true);
	mBackgroundSprite.setTexture(backgroungTexture);
	sf::IntRect rect(0, 0, mWindow.getSize().x, mWindow.getSize().y);
	mBackgroundSprite.setTextureRect(rect);
	// TODO: make scale adaptable to different resolutions
	mBackgroundSprite.setScale(3, 3);
}

void MenuState::setupOptions()
{
	for (int i = 0; i < static_cast<int>(Option::OptionCount); ++i)
	{
		Option option = static_cast<Option>(i);
		mOptionMap[option] = std::make_unique<sf::Text>();
		sf::Text &text = *mOptionMap[option];
		text.setString(getOptionText(option));
		text.setFont(*getContext().fontManager->get(Font::MineCraft));
		text.setCharacterSize(40);
		GraphicsHelper::centreOrigin(text);
		text.setFillColor(sf::Color::Black);
		const auto windowSize = mWindow.getSize();
		text.setPosition((float) windowSize.x * 3/4, 
						 (float) windowSize.y 
						 - 80 * (static_cast<int>(Option::OptionCount) - i));
	}

	updateOptionText();
}

void MenuState::drawOptions()
{
	for (auto const &pair : mOptionMap)
	{
		mWindow.draw(*pair.second);
	}
}

void MenuState::updateOptionText()
{
	for (auto &pair : mOptionMap)
	{
		pair.second->setFillColor(sf::Color::Black);
	}
	mOptionMap[mCurrentOption]->setFillColor(sf::Color::Green);
}
