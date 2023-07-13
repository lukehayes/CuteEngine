#include "CT/ECS/Component/TransformComponent.h"
#include "CT/Game.h"

namespace CT::ECS
{
  TransformComponent::TransformComponent(float x, float y, float w, float h, Color color, float speed)
    : position({x,y}),
      size({w,h}),
      color(color),
      dx(GetRandomValue(-1,1)),
      dy(GetRandomValue(-1,1)),
      speed(speed)
      {}


  void
  TransformComponent::update(double dt)
  {
  }
}
