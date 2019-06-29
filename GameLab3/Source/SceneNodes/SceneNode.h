#pragma once

#include <memory>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class SceneNode
	: public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	SceneNode();
	~SceneNode();

	void attachChild(std::unique_ptr<SceneNode> node);

	std::unique_ptr<SceneNode> detachChild(const SceneNode& node);

	void setParent(SceneNode* parent) { mParent = parent; }

	void resetParent() { mParent = nullptr; }

	void update(float deltaTime);

	sf::Transform getWorldTransform() const;

	sf::Vector2f getWorldPosition() const;

protected:
	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void updateSelf(float deltaTime);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void updateChildren(float deltaTime);

private:
	std::vector<std::unique_ptr<SceneNode>> mChildren;

	SceneNode* mParent;
};

