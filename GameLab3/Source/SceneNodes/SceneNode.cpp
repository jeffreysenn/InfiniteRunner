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
	mChildren.push_back(std::move(node));
	node->setParent(shared_from_this());
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


