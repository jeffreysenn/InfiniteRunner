#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "../Commands/Category.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <memory>
#include <vector>

class SceneNode
	: public sf::Transformable, private sf::NonCopyable
{
public:
	SceneNode();

	void attachChild(std::unique_ptr<SceneNode> node);
	std::unique_ptr<SceneNode> detachChild(const SceneNode& node);

	void setParent(SceneNode* parent) { mParent = parent; }
	const SceneNode* getParent() const { return mParent; }
	void resetParent() { mParent = nullptr; }

	void update(float deltaSeconds);

	void onCommand(const struct Command &command, float deltaSeconds);

	void reportRenderInfo(class Renderer &renderer, sf::RenderStates states = sf::RenderStates::Default) const;

	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;

	void setCategory(const Category &category) { mCategory = category; }
	Category getCategory() const { return mCategory; }

protected:
	virtual void updateSelf(float deltaSeconds);

	virtual void reportRenderInfoSelf(class Renderer &renderer, sf::RenderStates states) const;

private:
	void updateChildren(float deltaSeconds);

	void reportRenderInfoChildren(class Renderer &renderer, sf::RenderStates states) const;

protected:
	Category mCategory;

private:
	std::vector<std::unique_ptr<SceneNode>> mChildren;

	SceneNode* mParent;
};

