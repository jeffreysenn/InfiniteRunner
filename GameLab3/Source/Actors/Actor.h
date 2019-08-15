#pragma once
#include "../SceneNodes/SceneNode.h"

#include <SFML/System.hpp>


class Actor : public SceneNode
{
public:
	Actor();

	void setVelocity(const sf::Vector2f &velocity) { mVelocity = velocity; }
	void setVelocity(float vx, float vy) { mVelocity = sf::Vector2f(vx, vy); }

	sf::Vector2f getVelocity() const { return mVelocity; }

	sf::Vector2f getWorldVelocity() const;

protected:
	virtual void updateSelf(float deltaSeconds) override;

protected:
	sf::Vector2f mVelocity;
};

