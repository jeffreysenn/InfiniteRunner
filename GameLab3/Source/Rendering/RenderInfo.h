#pragma once


namespace Rendering
{
	enum Layer
	{
		Background,
		Midground,
		Forground,
		Default,
		UI,
		LayerCount,
	};
}

// Forward declaration
namespace sf
{
	class Drawable;
	class RenderStates;
}

struct RenderInfo
{
	const sf::Drawable* drawable = nullptr;
	sf::RenderStates states;
};


