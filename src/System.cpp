#include "ECS/System/System.h"

namespace ECS::System
{
    System::System(const std::string& name) : name(name) {}
    System::~System() {}

    str System::getName() const
    {
        return this->name;
    }

    void System::required(const std::initializer_list<std::string>& requirements)
    {
        for(auto r : requirements)
        {
            this->requirements.push_back(r);
        }
    }
}
