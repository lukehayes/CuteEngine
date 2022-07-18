#include "container/entity-container.h"

EntityContainer::EntityContainer() {}
EntityContainer::~EntityContainer() {}

void EntityContainer::render()
{
	for(auto &e : this->entities)
	{
		e.render();
	}
}

void EntityContainer::update(double delta)
{
	for(auto &e : this->entities)
	{
		e.update(delta);
	}
}

void EntityContainer::add(const Entity& entity)
{
	this->entities.push_back(entity);
}


EntityContainer entityContainer = {};
