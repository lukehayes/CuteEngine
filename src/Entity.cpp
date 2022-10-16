#include "ECS/Entity/Entity.h"

namespace ECS::Entity
{
    using ComponentBase = ECS::Component::Component;

    Entity::Entity() {}
    Entity::~Entity() {}

    void Entity::update(float delta) {}

    bool Entity::hasComponent(const std::string& name)
    {
        bool exists = false;

        for(auto c : this->components)
        {
            if(c.getName() == name)
            {
                exists = true;
            }
        }

        return exists;
    }

    std::vector<ComponentBase> Entity::getComponents() const
    {
        return this->components;
    }

    void Entity::addComponent(const ComponentBase& component)
    {
        this->components.push_back(component);
    }
}


