#include "ECS/System/System.h"

namespace ECS::System
{
    System::System(const std::string& name) : name(name) {}
    System::~System() {}

    str System::getName() const
    {
        return this->name;
    }
}
