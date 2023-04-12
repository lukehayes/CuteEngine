#include "ECS/System/MoveSystem.h"
#include "ECS/Component/TransformComponent.h"
#include "ECS/Component/SoundComponent.h"

#include "Game.h"
#include <cstdio>

namespace ECS
{
    void
    MoveSystem::update(double dt)
    {
        for(auto entity : entities)
        {
          // Transform Component is at index 0.
          if(!entity[0]) return;

          // Sound Component is at index 3.
          if(!entity[3]) return;

            auto* tc = dynamic_cast<ECS::TransformComponent*>(entity[0]);
            auto* sc = dynamic_cast<ECS::SoundComponent*>(entity[3]);

            static int SPEED = 500;

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

              sc->play();
            }
        }
    }
}
