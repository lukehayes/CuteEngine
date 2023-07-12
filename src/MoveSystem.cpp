#include "CT/ECS/System/MoveSystem.h"
#include "CT/ECS/Component/TransformComponent.h"
#include "CT/ECS/Component/SoundComponent.h"

#include "CT/Game.h"
#include "CT/Common/Types.h"
#include "CT/Common/Constants.h"
#include "CT/Common/Globals.h"

#include <math.h>

namespace CT::ECS
{
    using Entity = std::array<CT::ECS::Component*,4>;

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
