#pragma once

#include "ECS/System/System.h"

namespace ECS::System
{
    class PositionSystem : public System
    {
    public:
        PositionSystem();
        ~PositionSystem();

        /**
         * Update the system.
         *
         * @param float delta Delta time.
         */
        void update(float delta);
    };
}

