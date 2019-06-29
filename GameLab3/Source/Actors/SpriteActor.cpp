#include "SpriteActor.h"


SpriteActor::SpriteActor(const sf::Texture& texture)
	:mSprite(texture)
{
	sf::FloatRect rect(mSprite.getLocalBounds());
	mSprite.setOrigin(rect.width / 2, rect.height / 2);
}

SpriteActor::SpriteActor(const sf::Texture & texture, const sf::IntRect & rect)
	: mSprite(texture, rect)
{
}


SpriteActor::~SpriteActor()
{
}

void SpriteActor::drawSelf(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
