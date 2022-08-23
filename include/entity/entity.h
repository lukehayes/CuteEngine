#pragma once

#include "game-object.h"
#include "raylib.h"
#include "math/timer.h"
#include "collision/collision_rect.h"
#include <memory>


/**
 * Base game object that most entities should inherit.
 */
class Entity : public GameObject
{
	public:

		Entity(const Vector2& position, const Vector2& size, const float speed);

		~Entity();

		virtual void render();
		virtual void update(double dt);

		virtual void drawCollisionRect();

		Vector2 position;
		Vector2 size;
		double  speed;
		CollisionRect rect{{position.x, position.y, size.x,size.y}};
		Color color;


	private:
		void createEntityPtr();

};
