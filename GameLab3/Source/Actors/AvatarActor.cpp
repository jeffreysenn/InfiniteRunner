#include "AvatarActor.h"

#include "../Input/InputBinding.h"


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

void AvatarActor::updateSelf(float deltaSeconds)
{
	//if (Input::dataPressed(InputBinding::Jump))
	//{
	//	jump();
	//}

	//if (Input::dataPressed(InputBinding::Down))
	//{
	//	mLocalVel = sf::Vector2f(0, 50);
	//}

	setVelocity(mBaseVel + mLocalVel);

	SpriteActor::updateSelf(deltaSeconds);
}
