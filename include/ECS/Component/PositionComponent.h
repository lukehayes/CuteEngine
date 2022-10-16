#include <string>

namespace ECS::Component
{
    class PositionComponent : public Component
    {
    public:
            PositionComponent(float x, float y) : Component("Position"), x(x), y(y) {}
            ~PositionComponent() {}

            float x;
            float y;
    };
}

