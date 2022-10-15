#pragma once
#include <string>
#include "common/types.h"

namespace ECS
{
    /**
     * Base class for all systems.
     */
    class System
    {
    public:
            System();
            ~System();

            void update(float delta);

            /**
             * Set requirements for the specific system to work
             *
             * @param const std::string& requirements
             *
             */
            void required(const std::string& requirement);

            std::string getName() const;

    private:
            std::string name;
    };
}


