#ifndef SPRITE_H
#define SPRITE_H

#include <string>

class Sprite
{
public:
        Sprite(const std::string& filename) : texture(filename){}
        ~Sprite() {}

        /**
         * Draw the sprite at a specific location.
         *
         * @param float x    The x position of the texture.
         * @param float y    The y position of the texture.
         *
         * @return raylib::Texture&
         */
        raylib::Texture& Draw(float x, float y)
        {
            return this->texture.Draw(x,y);
        }

private:
    raylib::Texture texture;
};


#endif 

