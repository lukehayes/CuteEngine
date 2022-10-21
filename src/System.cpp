#include "ECS/System/System.h"

namespace ECS::System
{
    System::System(const std::string& name) : name() {}
    System::~System() {}

    void
    System::update(float delta)
    {
    }
}
