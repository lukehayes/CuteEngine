#pragma once

#include <string>

namespace ECS::Component
{
    class Component
    {
    public:
            Component();
            Component(const std::string& name);
            virtual ~Component();

            /**
             * Get the name of the component.
             *
             * @return std::string
             */
            std::string getName() const;

            /**
             * Get the id of the entity this component is attached to.
             *
             * @return int
             */
            inline int getEntityId() const { return this->entity_id; }


            int entity_id = 0;
    private:
            std::string name;

    };
}

