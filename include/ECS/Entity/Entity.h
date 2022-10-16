#include <vector>
#include "ECS/Component/Component.h"
#include <algorithm>

namespace ECS::Entity
{
    /**
     * Abstract base class for all entities.
     */
    class Entity
    {

    using ComponentBase = ECS::Component::Component;

    public:
            Entity();
            ~Entity();

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
             * Get the entities component.
             *
             * @param const std::string& name
             *
             * @return ECS::Component::Component
             */
            ECS::Component::Component getComponent(const std::string name)
            {
                auto res = std::find(this->components.begin(), this->components.end(), name);
            }

            /**
             * Get all of the entities components.
             *
             * @return std::vector<ECS::Component::Component>
             */
            std::vector<ComponentBase> getComponents() const;

            /**
             * Add a new component to the entity.
             *
             * @param ECS::Component::Component.
             */
            void addComponent(const ComponentBase& component);

    private:
            std::vector<ComponentBase> components;
    };
}


