#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"
#include "raylib-cpp.hpp"
#include <string>

class Sprite
{
public:
    Sprite(const std::string& filename, float x = 0, float y = 0, float scale = 2.0, float rotation = 0.0);
    ~Sprite();

    /**
     * Draw the sprite at a specific location.
     *
     * @param float x    The x position of the texture.
     * @param float y    The y position of the texture.
     *
     * @return raylib::Texture&
     */
    void Draw(float x, float y);

    raylib::Texture texture;
    float x;
    float y;
    float scale;
    float rotation;
};
#endif

