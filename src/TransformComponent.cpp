#include "ECS/TransformComponent.h"

namespace ECS
{
  TransformComponent::TransformComponent(float x, float y, float w, float h, Color color)
    : position({x,y}),size({w,h}), color(color) {}


  void
  TransformComponent::update(double dt)
  {
    printf("Updating Transform Component \n");
  }
}
