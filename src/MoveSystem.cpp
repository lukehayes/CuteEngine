#include "ECS/System/MoveSystem.h"
#include "ECS/Component/TransformComponent.h"
#include "ECS/Component/SoundComponent.h"

#include "Game.h"

#include <math.h>

namespace ECS
{
    void
    MoveSystem::update(double dt)
    {
        int TransformComponentIndex = 0;
        int SoundComponentIndex = 3;

        for(auto entity : entities)
        {
          // Transform Component is at index 0.
          if(!entity[TransformComponentIndex]) return;

          // Sound Component is at index 3.
          if(!entity[SoundComponentIndex]) return;

            auto* tc = dynamic_cast<ECS::TransformComponent*>(entity[TransformComponentIndex]);
            auto* sc = dynamic_cast<ECS::SoundComponent*>(entity[SoundComponentIndex]);
            sc->volume(0.07);

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

              int size = GetRandomValue(3,100);
              tc->size.x = size;
              tc->size.y = size;
            }
        }
    }
}
