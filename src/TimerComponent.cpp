#include "ECS/Component/TimerComponent.h"

#include <stdio.h>

namespace ECS
{
  TimerComponent::TimerComponent()
    : oneshot(false),
      time(1.0),
      elapsedTime(0.0),
      running(true)
  {}

  TimerComponent::TimerComponent(bool oneshot, double time)
    : oneshot(oneshot),
      time(time),
      elapsedTime(0.0),
      running(true)
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
