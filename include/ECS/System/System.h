#pragma once

#include "common/types.h"
#include "ECS/Component/Component.h"
#include "ECS/Entity/Entity.h"
#include "ECS/World.h"

#include <string>
#include <vector>

extern ECS::World world;

namespace ECS::System
{
    /**
     * A system can be defined to manage a particular set of components.
     */
    class System
    {
    public:
        System(const std::string& name);
        virtual ~System();

        void update(float delta);

        /**
         * Set requirements for the specific system to work
         *
         * @param const std::string& requirements
         */
        void required(const std::initializer_list<std::string>& requirements);

        /**
         * Check if an entity meets all of the systems component requirements.
         *
         * @param const ECS::Entity::Entity&
         *
         * @return bool Returns true if current entity has all required 
         *              components. False otherwise.
         */
        bool entityMeetsRequirements(ECS::Entity::Entity& entity);

        str getName() const;

    protected:
        std::vector<std::string> requirements;

    private:
            std::string name;
    };
}


