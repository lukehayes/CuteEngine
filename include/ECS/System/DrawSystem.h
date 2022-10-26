#pragma once

#include "ECS/System/System.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/Component/ColorComponent.h"
#include "ECS/World.h"
#include <memory>

extern ECS::World world;

namespace ECS::System
{
    class DrawSystem : public System
    {
    public:
            DrawSystem() : System("Draw") {}
            ~DrawSystem() {}

            void render()
            {
                for(auto& entity : world.entities)
                {
                    if(entityMeetsRequirements(entity))
                    {
                        auto pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(entity.getComponent("Position"));
                        auto color = std::dynamic_pointer_cast<ECS::Component::ColorComponent>(entity.getComponent("Color"));
                        DrawRectangle(pos->x, pos->y, 3,3, {color->r, color->g, color->b, color->a});
                    }
                }
            }
    };
}

