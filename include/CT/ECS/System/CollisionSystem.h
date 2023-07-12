#ifndef ECS_COLLISION_SYSTEM_H
#define ECS_COLLISION_SYSTEM_H

#include "CT/ECS/System/System.h"

namespace CT::ECS
{
  /**
   * Base class for all systems.
   */
  class CollisionSystem : public CT::ECS::System
  {
    public:

      /**
       * Update the system.
       *
       * @param double dt    Delta time.
       * 
       * @return void.
       */
      void update(double dt);
  };
}

#endif // ECS_COLLISION_SYSTEM_H
