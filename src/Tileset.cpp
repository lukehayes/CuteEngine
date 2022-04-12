#include "Tileset.h"

Tileset::Tileset(const std::string& imageFile, int width, int height, float tileSize, float scale) :
            texture(imageFile),
            width(width),
            height(height),
            tileSize(tileSize),
            scale(scale){}

Tileset::~Tileset()
{
    // TODO: Not sure if I need this?
    //this->texture.Unload();
}

void Tileset::Draw(float x, float y)
{
    DrawTextureEx(
            this->texture,
            {x,y},
            0.0f,
            this->scale,
            this->tint
            );
}

void Tileset::DrawTile(float x, float y, float tileX, float tileY)
{
    static float offset = 0.0;

    raylib::Rectangle src = {tileX * tileSize, tileY * tileSize, tileSize, tileSize};
    raylib::Rectangle dest = {x,y,tileSize * scale, tileSize * scale};

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

void Tileset::DrawAllTiles(float xp, float yp)
{
    for(float x = 0; x <= this->width - 1; x += 0.1)
    {
        for(float y = 0; y <= this->height - 1; y++)
        {
            raylib::Rectangle src = {x * (tileSize), y * (tileSize),tileSize, tileSize};
            raylib::Rectangle dest = {x * (tileSize * scale) + xp, y * (tileSize * scale) + yp, tileSize * scale, tileSize * scale};
            DrawTextureTiled(
                    this->texture,
                    src,
                    dest,
                    {0,0}, // Origin - Sets the origin of the image. Good for changing rotation origin.
                    //{tileSize / 2 * scale, tileSize / 2 * scale}, Rotate from center example.
                    0,
                    this->scale,
                    this->tint
                    );
        }
    }
}

