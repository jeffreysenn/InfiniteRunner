#include "Actor.h"

Actor::Actor()
	: SceneNode()
{
}


Actor::~Actor()
{
}

void Actor::updateSelf(float deltaTime)
{
	move(mVelocity*deltaTime);
}
