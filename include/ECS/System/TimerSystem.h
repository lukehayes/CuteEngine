#ifndef ECS_TIMER_SYSTEM_H
#define ECS_TIMER_SYSTEM_H

#include "ECS/System/System.h"

namespace ECS
{
  class TimerSystem : public ECS::System
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


#endif // ECS_TIMER_SYSTEM_H
