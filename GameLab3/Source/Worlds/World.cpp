#include "World.h"

#include "../Actors/ScrollingBackgroundActor.h"
#include "../Actors/CameraActor.h"
#include "../Actors/AvatarActor.h"

World::World(sf::RenderWindow &window)
	: mWindow(window)
	, mCamera(nullptr)
	, mAvatarActor(nullptr)
	, mScrollVelocity(30.f, 0)
{
	loadTextures();
	buildScene();
}

void World::loadTextures()
{
	mTextureManager.load(Texture::Back, "Assets/sunny-land-files/environment/back.png");
	mTextureManager.load(Texture::Middle, "Assets/sunny-land-files/environment/middle.png");
	mTextureManager.load(Texture::Avatar, "Assets/sunny-land-files/spritesheets/player-idle.png");
}

void World::buildScene()
{
	// Create and attach avatarActor to scene graph
	auto avatarTexture = mTextureManager.get(Texture::Avatar);
	std::unique_ptr<AvatarActor> avatarActor(
		std::make_unique<AvatarActor>(
		*avatarTexture,
		sf::IntRect(0, 0, 32, 32)
		));
	mAvatarActor = avatarActor.get();
	mAvatarActor->setPosition(mSpawnPosition);
	mAvatarActor->setBaseVelocity(20, 0); 
	mSceneGraph.attachChild(std::move(avatarActor));

	// Create a camera and attach to avatarActor
	std::unique_ptr<CameraActor> cameraActor(std::make_unique<CameraActor>());
	mCamera = cameraActor.get();
	mAvatarActor->attachChild(std::move(cameraActor));
	mCamera->setSize(320, 180);
	// Offset the camera
	mCamera->Actor::move(80, -30);

	// Create a background node and attach to the scene graph
	std::unique_ptr<SceneNode> backgroundNode(std::make_unique<SceneNode>());
	mBackgroundNode = backgroundNode.get();
	mSceneGraph.attachChild(std::move(backgroundNode));

	// Create scrolling background actors and attach to the background node
	// Get back texture and setup repeated
	auto backTxture = mTextureManager.get(Texture::Back);
	backTxture->setRepeated(true);
	// Create and attach backgroundNode to mBackground
	std::unique_ptr<ScrollingBackgroundActor> backActor(
		std::make_unique<ScrollingBackgroundActor>(
		*backTxture,
		sf::IntRect(0, 0, 384 * 2, 240),
		*mCamera,
		Rendering::Background,
		sf::Vector2f(0.9f, 0)));
	// Offset it
	backActor->move(0, -80);
	mBackgroundNode->attachChild(std::move(backActor));

	// Same for middle background
	auto midTexture = mTextureManager.get(Texture::Middle);
	midTexture->setRepeated(true);
	sf::IntRect midRect;
	std::unique_ptr<ScrollingBackgroundActor> midActor(
		std::make_unique<ScrollingBackgroundActor>(
		*midTexture,
		sf::IntRect(0, 0, 176 * 4, 368),
		*mCamera,
		Rendering::Midground,
		sf::Vector2f(0.2f, 0.1f)));
	midActor->move(0, 50);
	mBackgroundNode->attachChild(std::move(midActor));
}

void World::update(float deltaSeconds)
{
	mSceneGraph.update(deltaSeconds);
}

void World::draw()
{
	mWindow.setView(*mCamera);

	mSceneGraph.reportRenderInfo(mRenderer);
	mWindow.draw(mRenderer);
	mRenderer.clearRenderBuffer();
}

