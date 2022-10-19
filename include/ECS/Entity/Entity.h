#include "ECS/Component/Component.h"
#include <map>
#include <memory>

namespace ECS::Entity
{
    /**
     * Abstract base class for all entities.
     */
    class Entity
    {

    using ComponentBase = std::shared_ptr<ECS::Component::Component>;

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
             * Get the entities specific component.
             *
             * @param const std::string& name
             *
             * @return ECS::Component::Component
             */
            std::pair<std::string, ComponentBase>
            getComponent(const std::string name);

            /**
             * Get all of the entities components.
             *
             * @return std::vector<ECS::Component::Component>
             */
            std::map<std::string, ComponentBase> getComponents();

            /**
             * Add a new component to the entity.
             *
             * @param std::string name
             * @param ECS::Component::Component.
             */
            void addComponent(std::string name, ComponentBase& component);

    private:
            std::map<std::string, ComponentBase> components;
    };
}


