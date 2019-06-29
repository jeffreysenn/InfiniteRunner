#include "AvatarActor.h"



AvatarActor::AvatarActor(const sf::Texture& texture, Rendering::Layer layer)
	: SpriteActor(texture, layer)
{
}

AvatarActor::AvatarActor(const sf::Texture & texture, const sf::IntRect & rect, Rendering::Layer layer)
	: SpriteActor(texture, rect, layer)
{
}



AvatarActor::~AvatarActor()
{
}
