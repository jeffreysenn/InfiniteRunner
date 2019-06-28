#include "SpriteActor.h"


SpriteActor::SpriteActor()
{
}


SpriteActor::~SpriteActor()
{
}

void SpriteActor::drawSelf(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
