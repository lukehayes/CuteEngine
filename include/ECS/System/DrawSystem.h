#pragma once

#include "ECS/System/System.h"
#include "ECS/Component/DrawComponent.h"
#include <memory>

namespace ECS::System
{
    class DrawSystem : public System
    {
    public:
            DrawSystem() : System("Draw") {}
            ~DrawSystem() {}

            void render()
            {
                int requirement_size = this->requirements.size();
                int requirement_count = 0;

                ClearBackground(GRAY);
                BeginDrawing();

                // TODO Brute force method of checking if an entity
                // has the required components - refactor.
                for(auto& entity : world.entities)
                {
                    for(auto& req : this->requirements)
                    {
                        if(entity.hasComponent(req))
                        {
                            requirement_count++;
                        }
                    }

                    if(requirement_count == requirement_size)
                    {
                        auto pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(entity.getComponent("Position"));
                        auto color = std::dynamic_pointer_cast<ECS::Component::ColorComponent>(entity.getComponent("Color"));
                        DrawRectangle(pos->x, pos->y, 30,30, {color->r, color->g, color->b, color->a});

                        requirement_count = 0;
                    }else
                    {
                        requirement_count = 0;
                    }
                }

                EndDrawing();
            }
    };
}

