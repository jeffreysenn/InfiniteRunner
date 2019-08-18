#pragma once
#include "../ResourceManagers/ResourceIdentifiers.h"

#include <memory>

namespace sf
{
	class RenderWindow;
	class Time;
	class Event;
}

class PlayerController;
class StateStack;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{
		explicit Context(sf::RenderWindow& window, TextureManager& textureManager,
						 FontManager& fontManager, PlayerController& playerController);

		sf::RenderWindow* window;
		TextureManager* textureManager;
		FontManager* fontManager;
		PlayerController* playerController;
	};

public:
	explicit State(StateStack &stack, const Context &context);
	virtual ~State();

	virtual bool update(float deltaSeconds) { return true; }
	virtual bool handleEvent(const sf::Event &event) { return true; }
	virtual void draw() {}

protected:
	void requestStackPush(enum class StateID stateID);
	void requestStackPop();
	void requestStateClear();

	Context getContext() const;

private:
	StateStack &mStack;
	Context mContext;

};

