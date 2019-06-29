#pragma once
#include "Actor.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class SpriteActor :
	public Actor
{
public:
	explicit SpriteActor(const sf::Texture& texture);
	~SpriteActor();

	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite mSprite;
};

