#pragma once
#include "SpriteActor.h"

#include <SFML/Graphics/View.hpp>
class ScrollingBackgroundActor :
	public SpriteActor
{
public:
	explicit ScrollingBackgroundActor(const sf::Texture& texture, Rendering::Layer layer = Rendering::Background);

	ScrollingBackgroundActor(const sf::Texture& texture, const sf::IntRect& rect, Rendering::Layer layer = Rendering::Background);

	~ScrollingBackgroundActor();

	virtual void updateSelf(float deltaTime) override;

};

