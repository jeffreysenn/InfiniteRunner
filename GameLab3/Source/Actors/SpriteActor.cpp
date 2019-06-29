#include "SpriteActor.h"

#include "../Rendering/Renderer.h"

SpriteActor::SpriteActor(const sf::Texture& texture, Rendering::Layer layer)
	: mSprite(texture)
	, mLayer(layer)
{
	sf::FloatRect rect(mSprite.getLocalBounds());
	mSprite.setOrigin(rect.width / 2, rect.height / 2);
}

SpriteActor::SpriteActor(const sf::Texture & texture, const sf::IntRect& rect, Rendering::Layer layer)
	: mSprite(texture, rect)
	, mLayer(layer)
{
}


SpriteActor::~SpriteActor()
{
}

void SpriteActor::reportRenderInfoSelf(Renderer & renderer, sf::RenderStates states) const
{
	RenderInfo renderInfo{ &mSprite, states };
	renderer.pushRenderInfo(renderInfo, mLayer);
}

