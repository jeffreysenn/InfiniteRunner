#include "SceneNode.h"

#include <algorithm>
#include <cassert>

#include "../Rendering/Renderer.h"

SceneNode::SceneNode()
	: mParent(nullptr)
{
}

SceneNode::~SceneNode()
{
}

void SceneNode::attachChild(std::unique_ptr<SceneNode> node)
{
	node->setParent(this);
	mChildren.push_back(std::move(node));
}

std::unique_ptr<SceneNode> SceneNode::detachChild(const SceneNode &node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(),
							  [&node](std::unique_ptr<SceneNode> &ptr)
							  {
								  return ptr.get() == &node;
							  });

	assert(found != mChildren.end());

	(*found)->resetParent();
	mChildren.erase(found);
	return std::move(*found);
}

void SceneNode::update(float deltaSeconds)
{
	updateSelf(deltaSeconds);
	updateChildren(deltaSeconds);
}

void SceneNode::updateSelf(float deltaSeconds)
{
}

void SceneNode::updateChildren(float deltaSeconds)
{
	for (auto const &child : mChildren)
	{
		child->update(deltaSeconds);
	}
}

void SceneNode::reportRenderInfo(Renderer & renderer, sf::RenderStates states) const
{
	states.transform *= getTransform();

	reportRenderInfoSelf(renderer, states);

	reportRenderInfoChildren(renderer, states);
}

void SceneNode::reportRenderInfoSelf(Renderer & renderer, sf::RenderStates states) const
{
}

void SceneNode::reportRenderInfoChildren(Renderer & renderer, sf::RenderStates states) const
{
	for (auto const &child : mChildren)
	{
		child->reportRenderInfo(renderer, states);
	}
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
	{
		transform *= node->getTransform();
	}
	return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}



