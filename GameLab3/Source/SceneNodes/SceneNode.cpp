#include "SceneNode.h"

#include <algorithm>
#include <cassert>

SceneNode::SceneNode()
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

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	drawSelf(target, states);

	for (auto const &child : mChildren)
	{
		child->draw(target, states);
	}
}

void SceneNode::drawSelf(sf::RenderTarget & target, sf::RenderStates states) const
{
}

void SceneNode::update(float deltaTime)
{
	updateSelf(deltaTime);
	updateChildren(deltaTime);
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


void SceneNode::updateSelf(float deltaTime)
{
}

void SceneNode::updateChildren(float deltaTime)
{
	for (auto const &child: mChildren)
	{
		child->update(deltaTime);
	}
}

