#ifndef ECS_COLLISION_COMPONENT_H
#define ECS_COLLISION_COMPONENT_H

#include "ECS/Component/Component.h"

namespace ECS
{
    /**
     * Collision component checks for collisions.  
     */
    class CollisionComponent : public ECS::Component
    {
    public:

        /**
         * Update the component.
         *
         * @param double dt    Delta time.
         * 
         * @return void.
         */
        virtual void update(double dt) override;

        bool hasCollision();

    };
}

#endif // ECS_COLLISION_COMPONENT_H
