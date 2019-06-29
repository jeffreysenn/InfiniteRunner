#pragma once
#include "SpriteActor.h"

#include <SFML/Graphics/View.hpp>
class ScrollingBackgroundActor :
	public SpriteActor
{
public:
	explicit ScrollingBackgroundActor(const sf::Texture& texture, Rendering::Layer layer = Rendering::Background, sf::Vector2f scrollingVel = sf::Vector2f());

	ScrollingBackgroundActor(const sf::Texture& texture, const sf::IntRect& rect, Rendering::Layer layer = Rendering::Background, sf::Vector2f scrollingVel = sf::Vector2f());

	~ScrollingBackgroundActor();

	virtual void updateSelf(float deltaTime) override;

private:
	sf::Vector2f mOffset;

	sf::Vector2f mScrollingVel;
};

