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

            void update(float delta)
            {
            }

            void render()
            {

            }
        std::vector< std::shared_ptr<ECS::Component::DrawComponent> > components;
    };
}

