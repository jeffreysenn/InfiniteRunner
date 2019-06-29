#include "Actor.h"

Actor::Actor()
{
}


Actor::~Actor()
{
}

void Actor::updateSelf(float deltaTime)
{
	move(mVelocity*deltaTime);
}
