#include "SpriteNode.h"

SpriteNode::SpriteNode(const sf::Texture & texture)
	: SceneNode()
	, mSprite(texture)
{
}

SpriteNode::SpriteNode(const sf::Texture & texture, const sf::IntRect & rect)
	:mSprite(texture, rect)
{
}

void SpriteNode::drawSelf(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
