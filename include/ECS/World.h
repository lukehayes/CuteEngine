#pragma once

#include "common/types.h"
#include "ECS/Entity/Entity.h"
#include <vector>

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
            std::vector<ECS::Entity::Entity> entities;
    };
}

// Make the world global.
extern ECS::World world;

