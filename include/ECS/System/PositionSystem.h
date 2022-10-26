#pragma once

#include "ECS/System/System.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/World.h"
#include <memory>

extern ECS::World world;

namespace ECS::System
{
    class PositionSystem : public System
    {
    public:
        PositionSystem() : System("Position") {}
        ~PositionSystem() {}

        void update(float delta)
        {
            // TODO Brute force method of checking if an entity
            // has the required components - refactor.
            for(auto& entity : world.entities)
            {
                if(entityMeetsRequirements(entity))
                {
                    auto pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(entity.getComponent("Position"));

                    pos->x += pos->speed * pos->vx * delta;
                    pos->y += pos->speed * pos->vy * delta;

                    if(pos->x < 0 || pos->x > 580)
                    {
                        pos->vx = -pos->vx;
                    }

                    if(pos->y < 0 || pos->y > 480)
                    {
                        pos->vy = -pos->vy;
                    }
                }
            }
        }
    };
}

