#include "ECS/System/TimerSystem.h"
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
          // Transform Component is at index 0.
          if(!entity[TRANSFORM_COMPONENT_INDEX]) return;
          if(!entity[TIMER_COMPONENT_INDEX]) return;

            auto* tc = dynamic_cast<ECS::TransformComponent*>(entity[TRANSFORM_COMPONENT_INDEX]);
        }
    }
}
