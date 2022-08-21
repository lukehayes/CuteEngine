#pragma once

#include "raylib.h"

/**
 * Class defines a basic collision rect for simple collision detection.
 */
class CollisionRect
{
public:
	CollisionRect(const Rectangle& rect) 
		: rect(rect),
			thickness(1)
	{}

	~CollisionRect(){}

	/**
	 * Get the internal rect used for collision detection
	 *
	 * @return Rectangle.
	 */
	Rectangle getRect() const 
	{
		return this->rect;
	}

// private:	
	Rectangle rect;
	float thickness;

};
