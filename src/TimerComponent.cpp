#include "ECS/Component/TimerComponent.h"

#include <stdio.h>

namespace ECS
{
  TimerComponent::TimerComponent()
    : oneshot(false),
      running(true),
      finished(false),
      time(1.0),
      elapsedTime(0.0)
  {}

  TimerComponent::TimerComponent(bool oneshot, double time)
    : oneshot(false),
      running(true),
      finished(false),
      time(1.0),
      elapsedTime(0.0)
  {}

  void
  TimerComponent::update(double dt) 
  {
    this->elapsedTime += dt;

    if(this->running)
    {
      if(this->elapsedTime >= this->time)
      {
        printf("Timer Up\n");
        this->running = false;
      }
    }
  }
}
