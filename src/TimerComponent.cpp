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
    : oneshot(oneshot),
      running(true),
      finished(false),
      time(time),
      elapsedTime(0.0)
  {}

  void
  TimerComponent::update(double dt) {}
}
