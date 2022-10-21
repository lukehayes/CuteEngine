#include "ECS/Component/Component.h"


namespace ECS::Component
{
    Component::Component() :name("Component"), entity_id(0) {}
    Component::Component(const std::string& name) :name(name) {}
    Component::~Component() {}

    /**
     * Get the name of the component.
     *
     * @return std::string
     */
    std::string Component::getName() const
    {
        return this->name;
    }
}
