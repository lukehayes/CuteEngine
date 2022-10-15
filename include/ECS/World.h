#pragma once
#include <string>
#include "common/types.h"

namespace ECS
{
    /**
     * Base class for all systems.
     */
    class World
    {
    public:
            World();
            ~World();

            void update(float delta);
    };
}


