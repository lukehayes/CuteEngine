#include "container/entity-container.h"

EntityContainer::EntityContainer() {}
EntityContainer::~EntityContainer() {}

void EntityContainer::render()
{
	for(auto &e : this->entities)
	{
		e->render();
	}
}

void EntityContainer::update(double delta)
{
	for(auto &e : this->entities)
	{
		e->update(delta);
	}
}

void EntityContainer::add(const std::shared_ptr<Entity>& entity)
{
	this->entities.push_back(entity);
}

size_t EntityContainer::size() const
{
	return this->entities.size();
}

EntityContainer entityContainer = {};
