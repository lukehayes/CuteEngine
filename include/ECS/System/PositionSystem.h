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
                std::vector<ECS::Entity::Entity> ents;
                int requirement_size = this->requirements.size();

                // TODO Implement entity selection based on requirements.


                // for(auto& component : this->components)
                // {
                //     component->x += component->speed * component->vx * delta;
                //     component->y += component->speed * component->vy * delta;
                //
                //     if(component->x < 0 || component->x >= game.width)
                //     {
                //         component->vx = -component->vx;
                //     }
                //
                //     if(component->y < 0 || component->y >= game.width)
                //     {
                //         component->vy = -component->vy;
                //     }
                //
                // }
            }

        std::vector< std::shared_ptr<ECS::Component::PositionComponent> > components;
    };
}

