#include "bullet/bullet.h"
#include <cmath>

Bullet::Bullet(const Vector2& position, const Vector2& target)
    : Entity(position, {5,5}, 200),
    color({0,50,100, 255}),
    target(target),
    angle(this->getTargetAngle()),
    damage(1) {}

    Bullet::~Bullet() {}

void Bullet::render()
{
    DrawRectangle(
            position.x,
            position.y,
            size.x,
            size.y,
            color
            );

}
void Bullet::update(double dt)
{
    position.x -= std::cos(angle) * speed * dt;
    position.y -= std::sin(angle) * speed * dt;
}

float Bullet::getTargetAngle() const
{
    return std::atan2(position.y - target.y, position.x - target.x);
}
