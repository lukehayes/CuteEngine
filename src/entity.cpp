#include "entity/entity.h"
#include <cmath>

Entity::Entity()
{
	position.x = GetRandomValue(0,640);
	position.y = GetRandomValue(0,480);
	speed = GetRandomValue(0,250);
}

Entity::~Entity()
{
}

void Entity::render()
{
	DrawRectangle(
			position.x,
			position.y,
			10,
			10,
			DARKGRAY
			);
}

void Entity::update(double dt)
{
	static float c = 0.0;
	c+= 0.01;

	position.x += std::cos(c) * speed * dt;
	position.y += std::sin(c) * speed * dt;
}
