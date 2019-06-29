#pragma once
#include "SpriteActor.h"

class AvatarActor :
	public SpriteActor
{
public:
	explicit AvatarActor(const sf::Texture& texture, Rendering::Layer layer = Rendering::Default);

	AvatarActor(const sf::Texture& texture, const sf::IntRect &rect, Rendering::Layer layer = Rendering::Default);

	~AvatarActor();
};

