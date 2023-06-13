#ifndef ECS_TIMER_COMPONENT_H
#define ECS_TIMER_COMPONENT_H

#include "ECS/Component/Component.h"

namespace ECS
{
  /**
   * Timer component.
   */
  class TimerComponent : public ECS::Component
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
  };
}

#endif // ECS_COMPONENT_H
