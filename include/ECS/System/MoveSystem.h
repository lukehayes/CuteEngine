#ifndef ECS_MOVE_SYSTEM_H
#define ECS_MOVE_SYSTEM_H

#include "ECS/System/System.h"

namespace ECS
{
    class MoveSystem : public ECS::System
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



#endif // ECS_MOVE_SYSTEM_H
