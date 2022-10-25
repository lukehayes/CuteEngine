#pragma once

#include <string>
#include "ECS/Component/Component.h"

namespace ECS::Component
{
    class PositionComponent : public Component
    {
    public:
            PositionComponent(double x, double y, double vx, double vy)
                : Component("Position"), x(x), y(y), vx(vx), vy(vy) {}

            virtual ~PositionComponent() {}

            virtual double getX() { return this->x;}

            double x;
            double y;
            double vx;
            double vy;
            double speed = GetRandomValue(-5,5);
    };
}

