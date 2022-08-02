#pragma once

/**
 * Class defines a basic collision rect for simple collision detection.
 */
class CollisionRect
{
public:
	CollisionRect(const Rectangle& rect) 
		: rect(rect)
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

private:	
	Rectangle rect;
};
