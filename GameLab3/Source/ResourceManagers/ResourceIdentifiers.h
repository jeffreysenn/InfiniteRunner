#pragma once

#include "ResourceManager.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace Texture
{
	enum ID
	{
		Avatar,
		NONEXIST,
	};
}

namespace Font
{
	enum ID
	{

	};
}

namespace Sound
{
	enum ID
	{

	};
}

typedef ResourceManager<sf::Texture, Texture::ID> TextureManager;
