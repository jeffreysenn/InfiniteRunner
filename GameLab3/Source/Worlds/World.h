#pragma once
#include <SFML/System/NonCopyable.hpp>

#include "../ResourceManagers/ResourceIdentifiers.h"
#include "../SceneNodes/SceneNode.h"
#include "../Rendering/Renderer.h"

#include <array>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>



class World : private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);

	void update(float deltaTime);

	void draw();

private:
	void loadTextures();
	void buildScene();

private:
	sf::RenderWindow &mWindow;
	Renderer mRenderer;
	class CameraActor* mCamera;
	TextureManager mTextureManager;
	SceneNode mSceneGraph;
	class AvatarActor* mAvatarActor;
	sf::Vector2f mSpawnPosition;
	sf::Vector2f mScrollVelocity;
};

