
#ifndef CT_ECS_TRANSFORM_COMPONENT_H
#define CT_ECS_TRANSFORM_COMPONENT_H

#include "CT/ECS/Component/Component.h"
#include "raylib.h"

namespace CT::ECS
{
  /**
   * Base class for all components.
   */
  class TransformComponent : public Component
  {
    public:

      TransformComponent(float x, float y, float w, float h, Color color = PINK, float speed = 400);

      virtual void update(double dt);

      Vector2 position;
      Vector2 size;
      Color   color;
      float   dx; // X Direction
      float   dy; // Y Direction
      float   speed;
  };
}

#endif // ECS_TRANSFORM_COMPONENT_H
