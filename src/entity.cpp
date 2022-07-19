#include "entity/entity.h"
#include <cmath>

Entity::Entity(): 
	position(100,100),
	speed(GetRandomValue(0,100))
{}

Entity::Entity(const Vector2& position)
	:position(position),
	speed(100)
{}

Entity::Entity(const Vector2& position, const float speed)
	:position(position),
	speed(speed)
{}

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
