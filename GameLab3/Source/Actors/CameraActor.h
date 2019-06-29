#pragma once
#include <SFML/Graphics/View.hpp>
#include "Actor.h"

class CameraActor : public sf::View, public Actor
{
public:
	CameraActor();
	~CameraActor();

	virtual void updateSelf(float deltaTime) override;
};

