#pragma once
#include <string>
#include "common/types.h"

namespace ECS::System
{
    /**
     * Base class for all systems.
     */
    class System
    {
    public:
            System(const std::string& name);
            virtual ~System();

            virtual void update(float delta) = 0;

            /**
             * Set requirements for the specific system to work
             *
             * @param const std::string& requirements
             *
             */
            void required(const std::string& requirement);

            str getName() const;

    private:
            std::string name;
    };
}


