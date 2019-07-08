#include "CameraActor.h"

CameraActor::CameraActor()
	: Actor()
{
}


CameraActor::~CameraActor()
{
}

void CameraActor::updateSelf(float deltaSeconds)
{
	Actor::updateSelf(deltaSeconds);

	sf::View::setCenter(getWorldPosition());
}
