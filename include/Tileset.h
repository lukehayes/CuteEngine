#ifndef TILESET_H
#define TILESET_H

#include "raylib.h"
#include "raylib-cpp.hpp"
#include <string>

class Tileset
{
public:
    Tileset(const std::string& imageFile) : texture(imageFile){}

    ~Tileset()
    {
        // TODO: Not sure if I need this?
        //this->texture.Unload();
    }

    /**
     * Draw the whole texutre.
     *
     * @param float x    The x position of the texture.
     * @param float y    The y position of the texture.
     *
     * @return raylib::Texture&
     */
    raylib::Texture& Draw(float x = 0, float y = 0)
    {
        return this->texture.Draw(x,y);
    }

private:
    raylib::Texture texture;
};

#endif
