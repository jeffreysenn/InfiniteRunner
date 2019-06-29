#pragma once
#include "SpriteActor.h"

class AvatarActor :
	public SpriteActor
{
public:
	AvatarActor(const sf::Texture& texture);
	~AvatarActor();
};

