#pragma once

#include <memory>
#include <vector>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Transformable.hpp>

class SceneNode
	: public sf::Transformable, private sf::NonCopyable
{
public:
	SceneNode();
	~SceneNode();

	void attachChild(std::unique_ptr<SceneNode> node);

	std::unique_ptr<SceneNode> detachChild(const SceneNode& node);

	void setParent(SceneNode* parent) { mParent = parent; }

	void resetParent() { mParent = nullptr; }

	void update(float deltaTime);

	void reportRenderInfo(class Renderer &renderer, sf::RenderStates states = sf::RenderStates::Default) const;

	sf::Transform getWorldTransform() const;

	sf::Vector2f getWorldPosition() const;

protected:
	virtual void updateSelf(float deltaTime);

	virtual void reportRenderInfoSelf(class Renderer &renderer, sf::RenderStates states) const;

private:
	void updateChildren(float deltaTime);

	void reportRenderInfoChildren(class Renderer &renderer, sf::RenderStates states) const;

private:
	std::vector<std::unique_ptr<SceneNode>> mChildren;

	SceneNode* mParent;
};

