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
	//mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures()
{
	mTextureManager.load(Texture::Back, "assets/sunny-land-files/environment/back.png");
	mTextureManager.load(Texture::Avatar, "assets/sunny-land-files/spritesheets/player-idle.png");
}

void World::buildScene()
{
	// Build layers and attach them to mSceneGraph
	for (auto &layer : mSceneLayers)
	{
		std::unique_ptr<SceneNode> node(std::make_unique<SceneNode>());
		layer = node.get();
		mSceneGraph.attachChild(std::move(node));
	}

	// Create a camera
	std::unique_ptr<CameraActor> cameraActor(std::make_unique<CameraActor>());
	mCamera = cameraActor.get();
	cameraActor->setSize(1280, 720);

	// Get back texture and setup repeated
	auto backtTxture = mTextureManager.get(Texture::Back);
	//sf::IntRect textureRect(0, 0, (int) mWorldView.getSize().x, (int)mWorldView.getSize().y);
	backtTxture->setRepeated(true);
	// Create and attach backgroundNode to layer
	std::unique_ptr<ScrollingBackgroundActor> backgroundNode(std::make_unique<ScrollingBackgroundActor>(*backtTxture, *mCamera, mScrollVelocity));
	backgroundNode->setPosition(mCamera->getCenter());
	mSceneLayers[Background]->attachChild(std::move(backgroundNode));

	// Create and attach avatarActor to layer
	auto avatarTexture = mTextureManager.get(Texture::Avatar);
	std::unique_ptr<AvatarActor> avatarActor(std::make_unique<AvatarActor>(*avatarTexture));
	mAvatarActor = avatarActor.get();
	mAvatarActor->setPosition(mSpawnPosition);
	mAvatarActor->setVelocity(100, 100);
	// Attach mCamera to avatarActor
	sf::Vector2f cameraOffset(250, -150);
	cameraActor->setPosition(cameraOffset);
	mAvatarActor->attachChild(std::move(cameraActor));
	mSceneLayers[Foreground]->attachChild(std::move(avatarActor));

}

void World::update(float deltaTime)
{
	mSceneGraph.update(deltaTime);
}

void World::draw()
{
	mWindow.setView(*mCamera);
	mWindow.draw(mSceneGraph);
}

