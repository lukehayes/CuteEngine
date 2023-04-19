#include "ECS/System/CollisionSystem.h"

#include "ECS/Component/TransformComponent.h"
#include "ECS/Component/CollisionComponent.h"

namespace ECS
{
    void
    CollisionSystem::update(double dt) 
    {
        // TODO Implement collision detection component.
        // Horrible brute force solution at the moment
        // need to work on one using something
        // like a quadtree etc.

        EntityArray entities = *this->entities;

        for(int i = 0; i <= MAX_ENTITIES - 2; i++)
        {

            auto* tc = dynamic_cast<ECS::TransformComponent*>(entities[i][TRANSFORM_COMPONENT_INDEX]);

            for(int j = 0; j <= MAX_ENTITIES - 1; j++)
            {
                auto* tn = dynamic_cast<ECS::TransformComponent*>(entities[j][TRANSFORM_COMPONENT_INDEX]);

                if( tc->position.x > tn->position.x &&
                    tc->position.x < tn->size.x &&
                    tc->position.y > tn->position.y &&
                    tc->position.y < tn->size.y ){

                        int size = GetRandomValue(3,20);
                        tc->size.x = size;
                        tc->size.y = size;
                        printf("HIT \n");
                }


            }
        }

    }
}
