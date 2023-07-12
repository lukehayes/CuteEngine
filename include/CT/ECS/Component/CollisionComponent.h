#ifndef ECS_COLLISION_COMPONENT_H
#define ECS_COLLISION_COMPONENT_H

#include "CT/ECS/Component/Component.h"
#include "CT/Common/Types.h"

namespace CT::ECS
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

        /**
         * Check if the current component is colliding
         * with another entity.
         *
         * @param EntityArray* entities.
         *
         * @return bool
         */
        bool hasCollision(EntityArray& entities);

    };
}

#endif // ECS_COLLISION_COMPONENT_H
