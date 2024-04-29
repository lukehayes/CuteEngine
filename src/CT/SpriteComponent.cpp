#include "CT/ECS/Component/SpriteComponent.h"
#include <cstdio>

namespace CT::ECS
{
  SpriteComponent::SpriteComponent(std::shared_ptr<Texture2D> texture, float scale)
    : texture(texture),
      scale(scale) {}

  SpriteComponent::~SpriteComponent()
  {
  }
}

