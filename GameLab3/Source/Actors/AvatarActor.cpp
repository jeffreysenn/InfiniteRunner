#include "AvatarActor.h"


AvatarActor::AvatarActor(
	const sf::Texture &texture, 
	Rendering::Layer layer)
	: SpriteActor(texture, layer)
{
	mCategory = Category::Avatar;
}

AvatarActor::AvatarActor(
	const sf::Texture &texture, 
	const sf::IntRect &rect, 
	Rendering::Layer layer)
	: SpriteActor(texture, rect, layer)
{
	mCategory = Category::Avatar;
}

void AvatarActor::jump()
{
	mLocalVel.y = -50;
}

void AvatarActor::goStraight()
{
	mLocalVel = sf::Vector2f(0, 0);
}

void AvatarActor::updateSelf(float deltaSeconds)
{
	setVelocity(mBaseVel + mLocalVel);

	SpriteActor::updateSelf(deltaSeconds);
}
