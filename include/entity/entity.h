#pragma once

#include "game-object.h"
#include "raylib.h"
#include "collision/collision_rect.h"


/**
 * Base game object that most entities should inherit.
 */
class Entity : public GameObject
{
	public:

		Entity();

		Entity(const Vector2& position);
		Entity(const Vector2& position, const Vector2& size);
		Entity(const Vector2& position, const Vector2& size, const float speed);

		~Entity();

		virtual void render();
		virtual void update(double dt);

		Vector2 position;
		Vector2 size;
		CollisionRect collisionRect = {position, size};
		double  speed;
};
