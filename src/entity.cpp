#include "entity/entity.h"
#include <cmath>
#include "raylib.h"
#include "container/entity-container.h"

Entity::Entity(const Vector2& position, const Vector2& size, const float speed)
	:position(position),
	 size(size),
	 speed(speed),
	 color(DARKGRAY)
{
	// TODO Fix this rendering bug. Entity creation disabled for now.
	// this->createEntityPtr();
}

Entity::~Entity()
{
}

void Entity::createEntityPtr()
{
	std::shared_ptr<Entity> e = std::make_shared<Entity>(*this);
	entityContainer.add(e);
}

void Entity::drawCollisionRect()
{
	DrawRectangleLinesEx(
			rect.getRect(),
			rect.thickness,
			RED
	);
}

void Entity::render()
{
	DrawRectangle(
			position.x,
			position.y,
			size.x,
			size.y,
			color
			);

	this->drawCollisionRect();
}

void Entity::update(double dt)
{
	static float c = 0.0;
	c+= 0.01;

	position.x += std::cos(c) * speed * dt;
	position.y += std::sin(c) * speed * dt;

	rect.rect.x += std::cos(c) * speed * dt;
	rect.rect.y += std::sin(c) * speed * dt;
}
