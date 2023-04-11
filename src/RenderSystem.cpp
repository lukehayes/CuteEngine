#include "ECS/System/RenderSystem.h"
#include "ECS/TransformComponent.h"

#include "Game.h"


namespace ECS
{
  void
  RenderSystem::update(double dt)
  {
    for(auto entity : entities)
    {
      // Transform Component is at index 0.
      if(!entity[0]) return;

      auto* tc = dynamic_cast<ECS::TransformComponent*>(entity[0]);

      DrawRectangle(
          tc->position.x,
          tc->position.y,
          tc->size.x,
          tc->size.y,
          tc->color
      );


    }
  }
}
