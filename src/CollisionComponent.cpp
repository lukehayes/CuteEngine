
#include "ECS/Component/CollisionComponent.h"
#include <raylib.h>
#include <stdio.h>

#include "ECS/Component/TransformComponent.h"

namespace ECS
{
    void
    CollisionComponent::update(double dt) 
    {
    }

    bool
    CollisionComponent::hasCollision(EntityArray& entities)
    {
        // TODO Implement collision detection component.
        // Horrible brute force solution at the moment
        // need to work on one using something
        // like a quadtree etc.

        bool col = false;

        for(int i = 0; i <= MAX_ENTITIES - 2; i++)
        {
            auto tc = dynamic_cast<ECS::TransformComponent*>(entities[i][TRANSFORM_COMPONENT_INDEX]);
            auto tn = dynamic_cast<ECS::TransformComponent*>(entities[i + 1][TRANSFORM_COMPONENT_INDEX]);

                if(
                    tc->position.x > tn->position.x &&
                    tc->position.x < tn->size.x &&
                    tc->position.y > tn->position.y &&
                    tc->position.y < tn->size.y
                ){
                    int size = GetRandomValue(3,100);
                    tc->size.x = size;
                    tc->size.y = size;
                    printf("HIT \n");
                    col = true;
                }else {
                    col = false;
                }
        }

        return col;
    }

}
