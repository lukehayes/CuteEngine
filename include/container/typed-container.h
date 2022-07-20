#pragma once

#include <memory>


/**
 * A very basic container for all entities. Class just to test an idea.
 */
class TypedContainer
{
public:
	TypedContainer();
	~TypedContainer();

	void render();

	void update(double delta);

	void add(const Entity& entity);

	std::vector<Entity> entities;
};

extern TypedContainer typedContainer;
