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
	mTextureManager.load(Texture::Back, "assets/sunny-land-files/environment/back.png");
	mTextureManager.load(Texture::Middle, "assets/sunny-land-files/environment/middle.png");
	mTextureManager.load(Texture::Avatar, "assets/sunny-land-files/spritesheets/player-idle.png");
}

void World::buildScene()
{
	// Create a camera
	std::unique_ptr<CameraActor> cameraActor(std::make_unique<CameraActor>());
	mCamera = cameraActor.get();
	mSceneGraph.attachChild(std::move(cameraActor));
	mCamera->setSize(480, 270);
	mCamera->setVelocity(mScrollVelocity);

	// Create a background node and attach to the camera
	std::unique_ptr<SceneNode> backgroundNode(std::make_unique<SceneNode>());
	mBackgroundNode = backgroundNode.get();
	mCamera->attachChild(std::move(backgroundNode));

	// Create scrolling background actors and attach to the background node
	// Get back texture and setup repeated
	auto backTxture = mTextureManager.get(Texture::Back);
	backTxture->setRepeated(true);
	// Create and attach backgroundNode to mBackground
	std::unique_ptr<ScrollingBackgroundActor> backActor(
		std::make_unique<ScrollingBackgroundActor>(
		*backTxture,
		sf::IntRect(0, 0, 480, 240),
		Rendering::Background,
		mScrollVelocity));
	backActor->move(0, (384 - 480)/2);
	mBackgroundNode->attachChild(std::move(backActor));

	// Same for middle background
	auto midTexture = mTextureManager.get(Texture::Middle);
	midTexture->setRepeated(true);
	sf::IntRect midRect;
	std::unique_ptr<ScrollingBackgroundActor> midActor(
		std::make_unique<ScrollingBackgroundActor>(
		*midTexture,
		sf::IntRect(0, 0, 480, 368),
		Rendering::Midground,
		sf::Vector2f(60, 0)));
	// Offset it
	midActor->move(0, 100);
	mBackgroundNode->attachChild(std::move(midActor));


	// Create and attach avatarActor to scene graph
	auto avatarTexture = mTextureManager.get(Texture::Avatar);
	std::unique_ptr<AvatarActor> avatarActor(
		std::make_unique<AvatarActor>(
		*avatarTexture,
		sf::IntRect(0, 0, 32, 32)
		));
	mAvatarActor = avatarActor.get();
	mAvatarActor->setPosition(mSpawnPosition);
	mAvatarActor->setVelocity(30, 0);
	mSceneGraph.attachChild(std::move(avatarActor));
}

void World::update(float deltaTime)
{
	mSceneGraph.update(deltaTime);
}

void World::draw()
{
	mWindow.setView(*mCamera);
	mSceneGraph.reportRenderInfo(mRenderer);
	mWindow.draw(mRenderer);
	mRenderer.clearRenderBuffer();
}

