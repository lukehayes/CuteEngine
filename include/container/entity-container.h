#pragma once

#include "entity/entity.h"
#include <vector>

/**
 * A very basic container for all entities. Class just to test an idea.
 */
class EntityContainer
{
public:
	EntityContainer();
	~EntityContainer();

	void render();

	void update(double delta);

	void add(const Entity& entity);

	std::vector<Entity> entities;
};

extern EntityContainer entityContainer;
