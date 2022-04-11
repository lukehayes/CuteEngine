#ifndef TILESET_H
#define TILESET_H

#include "raylib.h"
#include "raylib-cpp.hpp"
#include <string>

class Tileset
{
public:
    Tileset(const std::string& imageFile, float tileSize, float scale = 3.0f, int width = 5, int height = 5) :
        texture(imageFile),
        tileSize(tileSize),
        scale(scale)
    {}

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
    void Draw(float x = 0, float y = 0)
    {
        DrawTextureEx(
                this->texture,
                {x,y},
                0.0f,
                this->scale,
                this->tint
                );
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
        float offset = 0;
        raylib::Rectangle src = {offset + tileSize * xp, offset + tileSize * yp, tileSize, tileSize};
        raylib::Rectangle dest = {x, y, tileSize * scale, tileSize * scale};
        return this->texture.DrawTiled(src, dest, {0,0}, 0, scale);
    }

    float scale;

private:
    raylib::Texture texture;
    float tileSize;
    int width;
    int height;
    Color tint = WHITE;
};

#endif
