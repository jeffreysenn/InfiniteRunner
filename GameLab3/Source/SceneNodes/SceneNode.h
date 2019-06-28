#pragma once

#include <memory>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class SceneNode
	: public std::enable_shared_from_this<SceneNode>,
	public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	SceneNode();
	~SceneNode();

	void attachChild(std::unique_ptr<SceneNode> node);

	std::unique_ptr<SceneNode> detachChild(const SceneNode& node);

	void setParent(std::shared_ptr<SceneNode> parent) { mParent = parent; }

	void resetParent() { mParent.reset(); }

protected:
	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	std::vector<std::unique_ptr<SceneNode>> mChildren;

	std::shared_ptr<SceneNode> mParent;
};

