#ifndef ECS_MOVE_SYSTEM_H
#define ECS_MOVE_SYSTEM_H

#include "CT/ECS/System/System.h"

namespace CT::ECS
{
    class MoveSystem : public CT::ECS::System
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
