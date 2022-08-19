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
		float rx = GetRandomValue(10,400);
		float ry = GetRandomValue(10,400);
		float rw = GetRandomValue(10,30);
		float rh = GetRandomValue(10,30);
		float speed = GetRandomValue(1,130);
		Vector2 p{rx,ry};
		Vector2 s{rw,rh};
		std::shared_ptr<Entity> e = std::make_shared<Entity>(p,s, speed);
		entityContainer.add(e);
	}
}

EntityContainer entityContainer = {};
