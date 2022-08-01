#pragma once

/**
 * Class defines a basic collision rect for simple collision detection.
 */
class CollisionRect
{
public:
	CollisionRect(const Vector2& position, const Vector2& size) 
		: position(position),
		  size(size)
	{}

	~CollisionRect(){}

	Vector2 position;
	Vector2 size;
};
