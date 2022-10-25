#pragma once

#include "common/types.h"
#include "ECS/Component/Component.h"

#include <string>
#include <vector>

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

            str getName() const;

    protected:
        std::vector<std::string> requirements;

    private:
            std::string name;
    };
}


