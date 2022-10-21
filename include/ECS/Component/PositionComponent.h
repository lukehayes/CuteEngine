#pragma once

#include <string>
#include "ECS/Component/Component.h"

namespace ECS::Component
{
    class PositionComponent : public Component
    {
    public:
            PositionComponent(double x, double y) : Component("Position"), x(x), y(y) {}
            ~PositionComponent() {}

            double x;
            double y;
    };
}

