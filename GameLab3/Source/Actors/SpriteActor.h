#pragma once
#include "Actor.h"

#include "../Rendering/RenderInfo.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class SpriteActor : public Actor
{
public:
	explicit SpriteActor(const sf::Texture& texture, Rendering::Layer layer = Rendering::Default);

	SpriteActor(const sf::Texture& texture, const sf::IntRect& rect, Rendering::Layer layer = Rendering::Default);

	void CentreOrigin();
	~SpriteActor();

	virtual void reportRenderInfoSelf(class Renderer &renderer, sf::RenderStates states) const override;

	void setLayer(Rendering::Layer layer) { mLayer = layer; }

	sf::Sprite* getSprite() { return &mSprite; }

protected:
	sf::Sprite mSprite;

	Rendering::Layer mLayer;
};

