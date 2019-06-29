#pragma once
#include "../SceneNodes/SceneNode.h"

#include <SFML/System.hpp>


class Actor : public SceneNode
{
public:
	Actor();
	~Actor();

	void setVelocity(const sf::Vector2f &velocity) { mVelocity = velocity; }

	void setVelocity(float vx, float vy) { mVelocity = sf::Vector2f(vx, vy); }

	sf::Vector2f getVelocity() const { return mVelocity; }

	virtual void updateSelf(float deltaTime) override;

private:
	sf::Vector2f mVelocity;
};

