#include "ScrollingBackgroundActor.h"

#include <cmath> 


ScrollingBackgroundActor::ScrollingBackgroundActor(const sf::Texture& texture, Rendering::Layer layer, sf::Vector2f scrollingVel)
	: SpriteActor(texture, layer)
	, mScrollingVel(scrollingVel)
	, mOffset(0, 0)
{
}

ScrollingBackgroundActor::ScrollingBackgroundActor(const sf::Texture &texture, const sf::IntRect & rect, Rendering::Layer layer, sf::Vector2f scrollingVel)
	: SpriteActor(texture, rect, layer)
	, mScrollingVel(scrollingVel)
	, mOffset(0, 0)
{
}

ScrollingBackgroundActor::~ScrollingBackgroundActor()
{
}

void ScrollingBackgroundActor::updateSelf(float deltaTime)
{
	SpriteActor::updateSelf(deltaTime);

	mOffset += mScrollingVel * deltaTime;

	// Making sure mTextRectPos does not go out of range
	mOffset.x = (float) std::fmod(mOffset.x, mSprite.getTexture()->getSize().x);
	mOffset.y = (float) std::fmod(mOffset.y, mSprite.getTexture()->getSize().y);

	sf::IntRect rect((int) mOffset.x,
					 (int) mOffset.y,
					 mSprite.getTextureRect().width,
					 mSprite.getTextureRect().height);

	mSprite.setTextureRect(rect);
}