#include "ScrollingBackgroundActor.h"



ScrollingBackgroundActor::ScrollingBackgroundActor(const sf::Texture& texture, Rendering::Layer layer)
	: SpriteActor(texture, layer)
{
}

ScrollingBackgroundActor::ScrollingBackgroundActor(const sf::Texture &texture, const sf::IntRect & rect, Rendering::Layer layer)
	: SpriteActor(texture, rect, layer)
{
}

ScrollingBackgroundActor::~ScrollingBackgroundActor()
{
}

void ScrollingBackgroundActor::updateSelf(float deltaTime)
{
	SpriteActor::updateSelf(deltaTime);

	mSprite.setTextureRect(sf::IntRect((int)(mSprite.getTextureRect().left+10), 0, mSprite.getTextureRect().width, mSprite.getTextureRect().height));
}