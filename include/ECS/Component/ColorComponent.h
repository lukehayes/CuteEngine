#include <string>

namespace ECS::Component
{
    class ColorComponent : public Component
    {
    public:
            ColorComponent(int r, int g, int b, int a) : Component("Color"), r(r), g(g), b(b), a(a) {}
            ~ColorComponent() {}

            int r;
            int g;
            int b;
            int a;

    };
}
