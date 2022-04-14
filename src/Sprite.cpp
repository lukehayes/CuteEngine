#include "Sprite.h"

Sprite::Sprite(const std::string& filename, float x, float y, float scale, float rotation) 
            : x(x),
              y(y),
              texture(filename),
              scale(scale),
              rotation(rotation)
        {}

Sprite::~Sprite() {}

void Sprite::Draw(float x, float y)
{
    DrawTextureEx(
            this->texture,
            {this->x,this->y},
            this->rotation,
            this->scale,
            WHITE
     );
}
