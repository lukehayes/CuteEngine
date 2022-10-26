#include "ECS/Entity/Entity.h"
#include <iostream>

namespace ECS::Entity
{
    Entity::Entity(int id) : entity_id(id) {}
    Entity::~Entity() {}

    void Entity::update(float delta) {}

    bool Entity::hasComponent(const std::string& name)
    {
        return this->components.contains(name);
    }

    std::map<std::string, std::shared_ptr<ECS::Component::Component>> Entity::getComponents()
    {
        return this->components;
    }

    std::shared_ptr<ECS::Component::Component>
    Entity::getComponent(const std::string name)
    {
        auto it = this->components.find(name);
        return (*it).second;
    }

    void Entity::addComponent(std::string name, const std::shared_ptr<ECS::Component::Component>& component)
    {
        this->components.insert(std::pair(name, component));
    }
}


