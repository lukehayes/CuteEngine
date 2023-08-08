#ifndef CT_ECS_SPRITE_COMPONENT_H
#define CT_ECS_SPRITE_COMPONENT_H

#include "CT/ECS/Component/Component.h"
#include "raylib.h"

namespace CT::ECS
{
  class SpriteComponent : public Component
  {
    public:
      SpriteComponent(Texture2D* texture, float scale);
      ~SpriteComponent();

      void update(double dt) override {}

      Texture2D* texture;
      float scale;
      float tileSize = 16;
  };
}


#endif //ECS_SPRITE_COMPONENT_H
