#include <string>
#include "ECS/Component/Component.h"
#include "common/types.h"

namespace ECS::Component
{
    class ColorComponent : public Component
    {
    public:
            ColorComponent(u8 r, u8 g, u8 b, u8 a) : Component("Color"), r(r), g(g), b(b), a(a) {}
            ~ColorComponent() {}

            u8 r;
            u8 g;
            u8 b;
            u8 a;

    };
}
