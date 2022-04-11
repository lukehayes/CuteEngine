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
    void DrawTile(float x = 0, float y = 0, float tileX = 0, float tileY = 0)
    {
        float offset = 0;
        raylib::Rectangle src = {offset + tileSize * tileX, offset + tileSize * tileY, tileSize, tileSize};
        raylib::Rectangle dest = {x * (tileSize * scale), y * (tileSize * scale), tileSize * scale, tileSize * scale};
        //raylib::Rectangle dest = {x * (scale * tileSize), y * (scale * tileSize), tileSize * scale, tileSize * scale};

        DrawTextureTiled(
                this->texture,
                src,
                dest,
                {0,0},
                0.0f,
                this->scale,
                this->tint
                );
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
