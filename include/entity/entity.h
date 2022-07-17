#pragma once

#include "game-object.h"
#include "raylib.h"


/**
 * Base game object that most entities should inherit.
 */
class Entity : public GameObject
{
	public:

		Entity();
		~Entity();

		virtual void render();
		virtual void update(double dt);

		Vector2 position;
		float speed;
};
