#ifndef ECS_SPRITE_COMPONENT_H
#define ECS_SPRITE_COMPONENT_H

#include "ECS/Component/Component.h"
#include "raylib.h"

namespace ECS
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
