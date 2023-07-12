#include "CT/ECS/Component/SpriteComponent.h"
#include <cstdio>

namespace CT::ECS
{
  SpriteComponent::SpriteComponent(const char* texture_path, float scale)
    : texture(LoadTexture(texture_path)),
      scale(scale) {}

  SpriteComponent::~SpriteComponent()
  {
    UnloadTexture(this->texture);
  }
}

