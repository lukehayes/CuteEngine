#pragma once

#include <iostream>
#include <memory>

/**
 * A very basic implementation of a quad tree.
 */
class QuadTree
{
	public:
		QuadTree() {}
		~QuadTree() {}
		QuadTree() default {}
		virtual ~QuadTree() {}
		void subdivide() {}

};
