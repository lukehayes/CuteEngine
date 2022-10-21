#pragma once
#include "ECS/System/System.h"
#include "ECS/Component/PositionComponent.h"
#include <memory>

namespace ECS::System
{
    class PositionSystem : public System
    {
    public:
            PositionSystem() : System("Position") {}
            ~PositionSystem() {}

            void update(float delta)
            {
                for(auto& component : this->components)
                {
                    component->x += component->vx * delta;
                    component->y += component->vy * delta;

                    DrawRectangle(
                            component->x,
                            component->y,
                            10,10,
                            {0,0,0,255}
                    );
                }
            }

        std::vector< std::shared_ptr<ECS::Component::PositionComponent> > components;
    };
}

