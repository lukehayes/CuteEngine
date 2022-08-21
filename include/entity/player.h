#pragma once

#include "entity/entity.h"

/**
 * Simple player test class.
 */
class Player : public Entity
{
public:
	Player(const Vector2& position);
	~Player();

	void render();
	void update(double dt);

	void shoot();

	Color color;
};
