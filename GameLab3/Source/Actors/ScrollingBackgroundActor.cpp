#include "ScrollingBackgroundActor.h"



ScrollingBackgroundActor::ScrollingBackgroundActor(const sf::Texture& texture, const sf::View& view, sf::Vector2f velocity)
	: SpriteActor(texture)
	, mView(view)
{
	setVelocity(velocity);
}

ScrollingBackgroundActor::ScrollingBackgroundActor(const sf::Texture & texture, const sf::IntRect & rect, const sf::View & view, sf::Vector2f velocity)
	: SpriteActor(texture, rect)
	, mView(view)
{
	setVelocity(velocity);
}

ScrollingBackgroundActor::~ScrollingBackgroundActor()
{
}

void ScrollingBackgroundActor::updateSelf(float deltaTime)
{
	SpriteActor::updateSelf(deltaTime);

	mSprite.setTextureRect(sf::IntRect((int)(mSprite.getTextureRect().left+10), 0, mSprite.getTextureRect().width, mSprite.getTextureRect().height));
}

sf::IntRect ScrollingBackgroundActor::getViewIntRect(const sf::View & View)
{
	return sf::IntRect(0,
					   0,
					   (int)mView.getSize().x,
					   (int)mView.getSize().y);
}


