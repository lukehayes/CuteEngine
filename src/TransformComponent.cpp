#include "ECS/Component/TransformComponent.h"
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
  }
}
