#pragma once

#include "entity/entity.h"

/**
 * Simple player test class.
 */
class Player : public Entity
{
public:
	Player();
	~Player();

	void render();
	void update(double dt);
};
