#include "CT/ECS/System/TimerSystem.h"
#include "CT/ECS/Component/TimerComponent.h"
#include "CT/ECS/Component/TransformComponent.h"
#include <cstdio>

namespace CT::ECS
{
    using Entity = std::array<CT::ECS::Component*,4>;

    void
    TimerSystem::update(double dt)
    {
        for(auto entity : *this->entities)
        {
            // Transform Component is at index 0.
            if(!entity[TRANSFORM_COMPONENT_INDEX]) return;
            if(!entity[TIMER_COMPONENT_INDEX])
            {
                printf("NO TIMRE \n");
                return;
            };

            auto* transform = dynamic_cast<ECS::TransformComponent*>(entity[TRANSFORM_COMPONENT_INDEX]);
            auto* timer = dynamic_cast<ECS::TimerComponent*>(entity[TIMER_COMPONENT_INDEX]);

            if(timer->elapsedTime < timer->time)
            {
                timer->elapsedTime += dt;
            }else
            {
            }
        }
    }
}
