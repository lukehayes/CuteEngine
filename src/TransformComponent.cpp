#include "ECS/TransformComponent.h"
#include "Game.h"

namespace ECS
{
  TransformComponent::TransformComponent(float x, float y, float w, float h, Color color)
    : position({x,y}),
      size({w,h}),
      color(color),
      dx(GetRandomValue(-1,1)),
      dy(GetRandomValue(-1,1))
      {}


  void
  TransformComponent::update(double dt)
  {
    static int SPEED = 200;

    // Movement.
    this->position.x += this->dx * SPEED * dt;
    this->position.y += this->dy * SPEED * dt;

    // Screen Edge Check.
    if(
      this->position.x < 10 || this->position.x > (game.width - 20) ||
      this->position.y < 10 || this->position.y > (game.height - 20)
    )
    {
      this->position.x = -this->dx;
      this->position.y = -this->dy;
    }
  }
}
