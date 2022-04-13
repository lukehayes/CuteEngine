#include "Sprite.h"

Sprite::Sprite(const std::string& filename, float scale, float rotation) 
            : texture(filename),
              scale(scale),
              rotation(rotation)
        {}

Sprite::~Sprite() {}

void Sprite::Draw(float x, float y)
{
    DrawTextureEx(
            this->texture,
            {x,y},
            this->rotation,
            this->scale,
            WHITE
     );
}
