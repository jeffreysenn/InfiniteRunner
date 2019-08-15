#pragma once

enum class Category : unsigned int
{
	None = 0,
	Scene = 1,
	Avatar = 1 << 1,
	Enemy = 1 << 2,
};

inline Category operator | (Category a, Category b)
{
	return static_cast<Category>(
		static_cast<unsigned int>(a)
		| static_cast<unsigned int>(b));
}

inline Category operator & (Category a, Category b)
{
	return static_cast<Category>(
		static_cast<unsigned int>(a)
		& static_cast<unsigned int>(b));
}