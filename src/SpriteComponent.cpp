#include "ECS/Component/SpriteComponent.h"
#include <cstdio>

namespace ECS
{
  SpriteComponent::SpriteComponent(Texture2D* texture, float scale)
    : texture(texture),
      scale(scale) {}

  SpriteComponent::~SpriteComponent()
  {
    // UnloadTexture(this->texture);
  }
}

