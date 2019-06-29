#pragma once
#include "SpriteActor.h"
class ScrollingBackgroundActor :
	public SpriteActor
{
public:
	explicit ScrollingBackgroundActor(const sf::Texture& texture, const sf::View& view, sf::Vector2f velocity = sf::Vector2f());

	explicit ScrollingBackgroundActor(const sf::Texture& texture, const sf::IntRect& rect ,const sf::View& view, sf::Vector2f velocity = sf::Vector2f());

	~ScrollingBackgroundActor();

	virtual void updateSelf(float deltaTime) override;

private:
	sf::IntRect getViewIntRect(const sf::View& View);
private:
	const sf::View& mView;
};

