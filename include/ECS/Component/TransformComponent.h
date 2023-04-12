
#ifndef ECS_TRANSFORM_COMPONENT_H
#define ECS_TRANSFORM_COMPONENT_H

#include "ECS/Component/Component.h"
#include "raylib.h"
#include <stdio.h>

namespace ECS
{
  /**
   * Base class for all components.
   */
  class TransformComponent : public Component
  {
    public:

      TransformComponent(float x, float y, float w, float h, Color color = PINK);

      virtual void update(double dt);

      Vector2 position;
      Vector2 size;
      Color   color;
      float   dx; // X Direction
      float   dy; // Y Direction
  };
}

#endif // ECS_TRANSFORM_COMPONENT_H
