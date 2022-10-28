#pragma once

#include <string>
#include "ECS/Component/Component.h"

namespace ECS::Component
{
    class PositionComponent : public Component
    {
    public:
            PositionComponent(Vector2 position, Vector2 velocity, int size = 5)
                : Component("Position"),
                  position(position),
                  velocity(velocity),
                  speed(GetRandomValue(-50,50)),
                  size(size)
            {}

            ~PositionComponent() {}

            Vector2 position;
            Vector2 velocity;
            double speed;
            int size;
    };
}

