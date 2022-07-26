#pragma once

#include "entity/entity.h"
#include <vector>
#include <memory>

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

	void add(std::unique_ptr<Entity>& entity);

	size_t size() const;

	std::vector<std::unique_ptr<Entity>> entities;
};

extern EntityContainer entityContainer;
