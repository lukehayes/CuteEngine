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

    /**
     * Draw a section of the texture.
     *
     * @param float x    The x position of the texture.
     * @param float y    The y position of the texture.
     *
     * @return raylib::Texture&
     */
    raylib::Texture& DrawTile(float x = 0, float y = 0, float xp = 0, float yp = 0)
    {
        float space = 1;
        float scale = 5.0f;
        raylib::Rectangle src = {space + 16 * xp, space + 16 * yp, 32, 32};
        raylib::Rectangle dest = {x,y, 16 * scale, 16 * scale};
        return this->texture.DrawTiled(src, dest, {0,0}, 0, scale);
    }

private:
    raylib::Texture texture;
};

#endif
