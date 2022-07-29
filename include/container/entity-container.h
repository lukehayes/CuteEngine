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

	void add(std::shared_ptr<Entity>& entity);

	size_t size() const;

	std::vector<std::shared_ptr<Entity>> entities;

	/**
	 * Fill the container with SIZE amount of entities.
	 *
	 *  @param int size    The amount of entities to add.
	 *
	 *  @return void.
	 *
	 **/
	void fill(int size);
};

extern EntityContainer entityContainer;
