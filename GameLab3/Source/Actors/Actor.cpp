#include "Actor.h"

Actor::Actor()
	: SceneNode()
{
}


Actor::~Actor()
{
}

sf::Vector2f Actor::getWorldVelocity() const
{
	sf::Vector2f worldVel = sf::Vector2f();
	for (const SceneNode* node = this; node != nullptr; node = node->getParent())
	{
		if (const Actor* actor = dynamic_cast<const Actor*>(node))
		{
			worldVel += actor->getVelocity();
		}
	}
	return worldVel;
}

void Actor::updateSelf(float deltaSeconds)
{
	move(mVelocity*deltaSeconds);
}
