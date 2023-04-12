#include "ECS/System/MoveSystem.h"
#include "ECS/TransformComponent.h"

#include "Game.h"

namespace ECS
{
    void
    MoveSystem::update(double dt)
    {
        for(auto entity : entities)
        {
          // Transform Component is at index 0.
          if(!entity[0]) return;

            auto* tc = dynamic_cast<ECS::TransformComponent*>(entity[0]);

            static int SPEED = 200;

            // Movement.
            tc->position.x += tc->dx * SPEED * dt;
            tc->position.y += tc->dy * SPEED * dt;

            // Screen Edge Check.
            if(
              tc->position.x < 5 || tc->position.x > (game.width - 5) ||
              tc->position.y < 5 || tc->position.y > (game.height - 5)
            )
            {
              tc->dx = -tc->dx;
              tc->dy = -tc->dy;
            }
        }
    }
}
