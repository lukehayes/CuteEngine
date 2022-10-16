#include <string>

namespace ECS::Component
{
    class ColorComponent : public Component
    {
    public:
            ColorComponent(float r, float g, float b) : Component("Color"), r(r), g(g), b(b) {}
            ~ColorComponent() {}

            float r;
            float g;
            float b;

    };
}
