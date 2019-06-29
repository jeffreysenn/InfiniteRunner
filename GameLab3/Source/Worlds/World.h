#pragma once
#include <SFML/System/NonCopyable.hpp>

#include <array>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../ResourceManagers/ResourceIdentifiers.h"
#include "../SceneNodes/SceneNode.h"

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
	enum Layer
	{
		Background,
		Midground,
		Foreground,
		UI,
		LayerCount
	};

private:
	sf::RenderWindow &mWindow;
	sf::View mWorldView;
	TextureManager mTextureManager;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	class AvatarActor* mAvatarActor;
	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
};

