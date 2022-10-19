#include "ECS/Entity/Entity.h"
#include <iostream>

namespace ECS::Entity
{
    using ComponentBase = std::shared_ptr<ECS::Component::Component>;

    Entity::Entity() {}
    Entity::~Entity() {}

    void Entity::update(float delta) {}

    bool Entity::hasComponent(const std::string& name)
    {
        return this->components.contains(name);
    }

    std::map<std::string, ComponentBase> Entity::getComponents()
    {
        return this->components;
    }

    ComponentBase
    Entity::getComponent(const std::string name)
    {
        auto it = this->components.find(name);
        return (*it).second;
    }

    void Entity::addComponent(std::string name, ComponentBase& component)
    {
        this->components.insert(std::pair(name, component));

        std::cout << "Added Entity ->" + name << ". Entities Size: " << this->components.size() << std::endl;
    }
}


