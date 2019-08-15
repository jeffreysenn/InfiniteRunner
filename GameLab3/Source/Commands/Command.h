#pragma once
#include "Category.h"

#include <functional>
#include <cassert>

struct Command
{
	std::function<void(class SceneNode &, float)> action;
	Category category = Category::None;
};

template<typename Actor, typename Function>
std::function<void(SceneNode&, float)> derivedAction(Function fn)
{
	return [=](SceneNode &node, float deltaSeconds)
	{
		assert(dynamic_cast<Actor*>(&node) != nullptr);
		fn(static_cast<Actor&>(node), deltaSeconds);
	};
}