#pragma once

#include <string>
#include "ECS/Component/Component.h"

namespace ECS::Component
{
    class PositionComponent : public Component
    {
    public:
            PositionComponent(double x, double y, double vx, double vy) : Component("Position"), x(x), y(y), vx(vx), vy(vy) {}
            ~PositionComponent() {}

            double x;
            double y;
            double vx;
            double vy;
    };
}

