#include "ECS/System/MoveSystem.h"
#include "ECS/Component/TransformComponent.h"
#include "ECS/Component/SoundComponent.h"

#include "Game.h"
#include "Common/Types.h"
#include "Common/Constants.h"
#include "Common/Globals.h"

#include <math.h>

namespace ECS
{
    using Entity = std::array<ECS::Component*,4>;

    void checkCollision(Entity& entity)
    {
        auto* tc = dynamic_cast<ECS::TransformComponent*>(entity[TRANSFORM_COMPONENT_INDEX]);

        // Screen Edge Check.
        if(
          tc->position.x < 5 || tc->position.x > (game.width - 5) ||
          tc->position.y < 5 || tc->position.y > (game.height - 5)
        )
        {
          tc->dx = -tc->dx;
          tc->dy = -tc->dy;

          int size = GetRandomValue(3,100);
          tc->size.x = size;
          tc->size.y = size;
        }
    }

    void
    MoveSystem::update(double dt)
    {
        for(auto entity : *this->entities)
        {
          // Transform Component is at index 0.
          if(!entity[TRANSFORM_COMPONENT_INDEX]) return;

            auto* tc = dynamic_cast<ECS::TransformComponent*>(entity[TRANSFORM_COMPONENT_INDEX]);

            // Movement.
            tc->position.x += tc->dx * tc->speed * dt;
            tc->position.y += tc->dy * tc->speed * dt;

            checkCollision(entity);
        }
    }
}
