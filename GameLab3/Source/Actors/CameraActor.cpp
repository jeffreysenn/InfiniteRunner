#include "CameraActor.h"



CameraActor::CameraActor()
	: Actor()
{
}


CameraActor::~CameraActor()
{
}

void CameraActor::updateSelf(float deltaTime)
{
	Actor::updateSelf(deltaTime);

	sf::View::setCenter(getWorldPosition());
}
