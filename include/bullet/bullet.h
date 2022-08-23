#pragma once

#include "entity/entity.h"

class Bullet : public Entity
{
public:
	Bullet(const Vector2& position, const Vector2& size, const float speed);
  virtual ~Bullet();

	virtual void render();
	virtual void update(double dt);


	Color   color;
	Vector2 target;
	float   angle;
	int     damage;

private:
	float getTargetAngle() const;
};

