#include "ScrollingBackgroundActor.h"

#include <cmath> 


ScrollingBackgroundActor::ScrollingBackgroundActor(
	const sf::Texture& texture,
	const CameraActor& camera,
	Rendering::Layer layer,
	sf::Vector2f moveWithCameraFactor)
	: SpriteActor(texture, layer)
	, mCamera(camera)
	, mMoveWithCameraFactor(moveWithCameraFactor)
{
}

ScrollingBackgroundActor::ScrollingBackgroundActor(
	const sf::Texture &texture,
	const sf::IntRect & rect,
	const CameraActor& camera,
	Rendering::Layer layer,
	sf::Vector2f moveWithCameraFactor)
	: SpriteActor(texture, rect, layer)
	, mCamera(camera)
	, mMoveWithCameraFactor(moveWithCameraFactor)
{
}

ScrollingBackgroundActor::~ScrollingBackgroundActor()
{
}

void ScrollingBackgroundActor::updateSelf(float deltaSeconds)
{
	auto camaraVel = mCamera.getWorldVelocity();
	setVelocity(camaraVel.x * mMoveWithCameraFactor.x,
				camaraVel.y * mMoveWithCameraFactor.y);

	SpriteActor::updateSelf(deltaSeconds);

	/* 
		A bit hacky. We create a sprite more than twice of the width of the camera view.
		When we know the right camera view bound is hitting the right sprite bound, 
		we move the sprite to the right by half of its width. 
	*/
	float cameraRightBound = mCamera.getCenter().x + mCamera.getSize().x / 2;
	float spriteRightBound = getWorldPosition().x + mSprite.getLocalBounds().width / 2;
	
	if (cameraRightBound >= spriteRightBound)
	{
		move(mSprite.getLocalBounds().width/2, 0);
	}
}