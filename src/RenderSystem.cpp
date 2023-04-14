#include "ECS/System/RenderSystem.h"
#include "ECS/Component/TransformComponent.h"
#include "Common/Globals.h"

#include "Game.h"

namespace ECS
{
  void
  RenderSystem::update(Color clearColor, double dt) 
  {
    ClearBackground(clearColor);
    BeginDrawing();

    for(auto entity : this->entities)
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

    EndDrawing();
  }
}
