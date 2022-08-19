#pragma once

#include "game-object.h"
#include "raylib.h"
#include "math/timer.h"
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
		double  speed;
		CollisionRect rect{{position.x, position.y, size.x,size.y}};
};
