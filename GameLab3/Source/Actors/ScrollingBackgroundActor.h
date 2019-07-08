#pragma once
#include "SpriteActor.h"

#include "CameraActor.h"

#include <SFML/Graphics/View.hpp>

// TODO: Generalize this class so it can support vertical scrolling
class ScrollingBackgroundActor :
	public SpriteActor
{
public:
	explicit ScrollingBackgroundActor(
		const sf::Texture& texture, 
		const CameraActor& camera, 
		Rendering::Layer layer = Rendering::Background, 
		sf::Vector2f moveWithCameraFactor = sf::Vector2f());

	ScrollingBackgroundActor(
		const sf::Texture& texture, 
		const sf::IntRect& rect,
		const CameraActor& camera, 
		Rendering::Layer layer = Rendering::Background, 
		sf::Vector2f moveWithCameraFactor = sf::Vector2f());

	~ScrollingBackgroundActor();

protected:
	virtual void updateSelf(float deltaSeconds) override;

private:
	const CameraActor& mCamera;

	sf::Vector2f mMoveWithCameraFactor;
};

