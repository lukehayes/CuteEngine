#include "entity/entity.h"
#include <cmath>

Entity::Entity(): 
	position(100,100),
	size(100,100),
	speed(GetRandomValue(0,100))
{}

Entity::Entity(const Vector2& position)
	:position(position),
	 size(10),
	 speed(GetRandomValue(0,100))
{}

Entity::Entity(const Vector2& position, const Vector2& size)
	:position(position),
	 size(size),
	 speed(100)
{}

Entity::Entity(const Vector2& position, const Vector2& size, const float speed)
	:position(position),
	 size(size),
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
			size.x,
			size.y,
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
