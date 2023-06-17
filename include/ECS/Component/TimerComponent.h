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

      // TODO Need to implement what the timer should do after
      //      the it has finished - callback fn or similar.

      TimerComponent();

      TimerComponent(bool oneshot, double time);

      /**
       * Update the component.
       *
       * @sparam double dt    Delta time.
       * 
   s    * @return void.
       */
      virtual void update(double dt) override;

      bool   oneshot;
      double time;
      double elapsedTime;
      bool running;

  };
}

#endif // ECS_COMPONENT_H
