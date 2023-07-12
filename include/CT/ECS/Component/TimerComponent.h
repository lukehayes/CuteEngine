#ifndef CT_ECS_TIMER_COMPONENT_H
#define CT_ECS_TIMER_COMPONENT_H

#include "CT/ECS/Component/Component.h"

namespace CT::ECS
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
       * @param double dt    Delta time.
       *
       * @return void.
       */
      virtual void update(double dt) override;

      bool   oneshot;
      bool   running;
      bool   finished;
      double time;
      double elapsedTime;

  };
}

#endif // ECS_COMPONENT_H
