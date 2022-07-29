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

void EntityContainer::add(std::shared_ptr<Entity>& entity)
{
	this->entities.push_back(entity);
	//this->entities.push_back(std::move(entity));
}

size_t EntityContainer::size() const
{
	return this->entities.size();
}
void EntityContainer::fill(int size) 
{
	for(int i = 0; i <= size; i++)
	{
		Vector2 v{(float)i * 10, (float)i * 10};
		std::shared_ptr<Entity> e = std::make_shared<Entity>(v);
		entityContainer.add(e);
	}
}

EntityContainer entityContainer = {};
