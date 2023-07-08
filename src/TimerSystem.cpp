#include "ECS/System/TimerSystem.h"
#include "ECS/Component/TimerComponent.h"
#include "ECS/Component/TransformComponent.h"
#include <cstdio>

namespace ECS
{
    using Entity = std::array<ECS::Component*,4>;

    void
    TimerSystem::update(double dt)
    {
        for(auto entity : *this->entities)
        {
            if(!entity[TRANSFORM_COMPONENT_INDEX]) return;
            if(!entity[TIMER_COMPONENT_INDEX])     return;

            auto* transform = dynamic_cast<ECS::TransformComponent*>(entity[TRANSFORM_COMPONENT_INDEX]);
            auto* timer = dynamic_cast<ECS::TimerComponent*>(entity[TIMER_COMPONENT_INDEX]);

            if(timer->elapsedTime < timer->time)
            {
                timer->elapsedTime += dt;
            }else
            {
                transform->color = Color(255,255,255,120);
            }
        }
    }
}
