#pragma once

#include "ECS/Component/Component.h"
#include "common/types.h"
#include <map>
#include <memory>

namespace ECS::Entity
{
    /**
     * Abstract base class for all entities.
     */
    class Entity
    {

    public:
            /**
             * Constructor.
             *
             * @param int id     The id of this particular entity.
             *
             * @abstract
             */
            Entity(int id);
            virtual ~Entity();

            /**
             * Update the entity.
             *
             * @param float delta Delta time
             *
             * @abstract
             */
            void update(float delta);

            /**
             * Check if the entity has a specific component.
             *
             * @param const std::string& name
             *
             * @return bool
             */
            bool hasComponent(const std::string& name);

            /**
             * Get the entities specific component.
             *
             * @param const std::string& name
             *
             * @return ECS::Component::Component
             */
            std::shared_ptr<ECS::Component::Component>
            getComponent(const std::string name);

            virtual void sexy()
            {

            }

            /**
             * Get all of the entities components.
             *
             * @return std::vector<ECS::Component::Component>
             */
            std::map<std::string, std::shared_ptr<ECS::Component::Component>> getComponents();

            /**
             * Add a new component to the entity.
             *
             * @param std::string name
             * @param ECS::Component::Component.
             */
            void addComponent(std::string name, const std::shared_ptr<ECS::Component::Component>& component);

            s8 entity_id;
    private:
            std::map<std::string,std::shared_ptr<ECS::Component::Component>> components;
    };
}


