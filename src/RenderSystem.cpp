#include "ECS/System/RenderSystem.h"
#include "ECS/Component/TransformComponent.h"
#include "ECS/Component/SpriteComponent.h"

#include "Game.h"
#include <cstdio>

namespace ECS
{
  void
  RenderSystem::update(Color clearColor, double dt) 
  {
    ClearBackground(clearColor);
    BeginDrawing();

    for(auto entity : *this->entities)
    {
        // Transform Component is at index 0.
        if(!entity[TRANSFORM_COMPONENT_INDEX]) return;
        auto* tc = dynamic_cast<ECS::TransformComponent*>(entity[TRANSFORM_COMPONENT_INDEX]);

        auto* sc = dynamic_cast<ECS::SpriteComponent*>(entity[SPRITE_COMPONENT_INDEX]);

        if(sc)
        {
          DrawTexturePro(
              sc->texture,
              {0,0, 100,100},
              {tc->position.x, tc->position.y, sc->tileSize * sc->scale, sc->tileSize * sc->scale},
              {0,0},
              0.0,
              WHITE
              );
        }else
        {
          DrawRectangle(
              tc->position.x,
              tc->position.y,
              tc->size.x,
              tc->size.y,
              tc->color
            );
        }
    }

    EndDrawing();
  }
}
