#pragma once
#include "Actor.h"

#include "../Rendering/RenderInfo.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class SpriteActor : public Actor
{
public:
	explicit SpriteActor(const sf::Texture& texture, Rendering::Layer layer = Rendering::Default);
	SpriteActor(const sf::Texture& texture, const sf::IntRect& rect, Rendering::Layer layer = Rendering::Default);
	~SpriteActor();

	virtual void reportRenderInfoSelf(class Renderer &renderer, sf::RenderStates states) const override;

protected:
	sf::Sprite mSprite;

	Rendering::Layer mLayer;
};

