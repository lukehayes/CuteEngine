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
		virtual ~QuadTree() {}
		void subdivide() {}

		constexpr MAX_QUADS = 4;
		constexpr MAX_ITERATIONS = 6;
};
