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
	mTextureManager.load(Texture::Avatar, "assets/sunny-land-files/spritesheets/player-idle.png");
}

void World::buildScene()
{
	// Create a camera
	std::unique_ptr<CameraActor> cameraActor(std::make_unique<CameraActor>());
	mCamera = cameraActor.get();
	cameraActor->setSize(384, 240);

	// Get back texture and setup repeated
	auto backtTxture = mTextureManager.get(Texture::Back);
	backtTxture->setRepeated(true);
	// Create and attach backgroundNode to layer
	std::unique_ptr<ScrollingBackgroundActor> backgroundNode(std::make_unique<ScrollingBackgroundActor>(*backtTxture, Rendering::Background));
	cameraActor->attachChild(std::move(backgroundNode));

	// Create and attach avatarActor to layer
	auto avatarTexture = mTextureManager.get(Texture::Avatar);
	std::unique_ptr<AvatarActor> avatarActor(std::make_unique<AvatarActor>(*avatarTexture));
	mAvatarActor = avatarActor.get();
	mAvatarActor->setPosition(mSpawnPosition);
	mAvatarActor->setVelocity(100, 100);
	// Attach mCamera to avatarActor
	sf::Vector2f cameraOffset(0, 0);
	cameraActor->setPosition(cameraOffset);
	mAvatarActor->attachChild(std::move(cameraActor));
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

