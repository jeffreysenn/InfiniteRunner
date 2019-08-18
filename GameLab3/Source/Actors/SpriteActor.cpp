#include "SpriteActor.h"

#include "../Rendering/Renderer.h"

SpriteActor::SpriteActor(const sf::Texture& texture, Rendering::Layer layer)
	: mSprite(texture)
	, mLayer(layer)
{
	CentreOrigin();
}

SpriteActor::SpriteActor(const sf::Texture & texture, const sf::IntRect& rect, Rendering::Layer layer)
	: mSprite(texture, rect)
	, mLayer(layer)
{
	CentreOrigin();
}

void SpriteActor::CentreOrigin()
{
	sf::FloatRect spriteBounds(mSprite.getLocalBounds());
	mSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
}


SpriteActor::~SpriteActor()
{
}

void SpriteActor::reportRenderInfoSelf(Renderer & renderer, sf::RenderStates states) const
{
	RenderInfo renderInfo(mSprite, states); 
	renderer.pushRenderInfo(renderInfo, mLayer);
}
