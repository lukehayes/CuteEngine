#ifndef ECS_COLLISION_SYSTEM_H
#define ECS_COLLISION_SYSTEM_H

#include "ECS/System/System.h"

namespace ECS
{
  /**
   * Base class for all systems.
   */
  class CollisionSystem : public ECS::System
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
