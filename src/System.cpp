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
    bool System::entityMeetsRequirements(ECS::Entity::Entity& entity)
    {
        int requirement_size = this->requirements.size();
        int requirement_count = 0;
        bool meetsRequirements = false;

        for(auto& req : this->requirements)
        {
            if(entity.hasComponent(req))
            {
                requirement_count++;
            }
        }

        if(requirement_count == requirement_size)
        {
            meetsRequirements = true;
            requirement_count = 0;
        }else
        {
            meetsRequirements = false;
            requirement_count = 0;
        }
        return meetsRequirements;
    }
}
