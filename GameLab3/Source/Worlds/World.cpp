#include "World.h"

#include "../SceneNodes/SpriteNode.h"
#include "../Actors/AvatarActor.h"

World::World(sf::RenderWindow &window)
	: mWindow(window)
	, mWorldView(mWindow.getDefaultView())
	, mWorldBounds( 0.f, 0.f, 5000.f, mWorldView.getSize().y)
	, mSpawnPosition( mWorldView.getSize().x / 3, mWorldBounds.height * 2 / 3 )
	, mAvatarActor(nullptr)
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

	// Get back texture and setup repeated
	auto backtTxture = mTextureManager.get(Texture::Back);
	sf::IntRect textureRect(mWorldBounds);
	backtTxture->setRepeated(true);
	// Create and attach backgroundNode to layer
	std::unique_ptr<SpriteNode> backgroundNode(std::make_unique<SpriteNode>(*backtTxture, textureRect));
	backgroundNode->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundNode));

	// Create and attach avatarActor to layer
	auto avatarTexture = mTextureManager.get(Texture::Avatar);
	std::unique_ptr<AvatarActor> avatarActor(std::make_unique<AvatarActor>(*avatarTexture));
	mAvatarActor = avatarActor.get();
	mAvatarActor->setPosition(mSpawnPosition);
	mAvatarActor->setVelocity(40.f, 0);
	mSceneLayers[Foreground]->attachChild(std::move(avatarActor));
}

void World::update(float deltaTime)
{
	mWorldView.move(30.f * deltaTime, 0.f);

	mSceneGraph.update(deltaTime);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

