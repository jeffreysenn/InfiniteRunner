#pragma once
#include "Actor.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class SpriteActor :
	public Actor
{
public:
	SpriteActor();
	~SpriteActor();

	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite mSprite;
};

