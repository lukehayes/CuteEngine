#ifndef TILESET_H
#define TILESET_H

#include "raylib.h"
#include "raylib-cpp.hpp"
#include <string>

class Tileset
{
    public:
        Tileset(const std::string& imageFile, int width = 8, int height = 12, float tileSize = 16, float scale = 3.0f) :
            texture(imageFile),
            width(width),
            height(height),
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
            static float offset = 0.0;
            raylib::Rectangle src = {x * (tileSize), y * (tileSize),tileSize, tileSize};
            raylib::Rectangle dest = {x * (tileSize * scale), y * (tileSize * scale), tileSize * scale, tileSize * scale};

            offset += 1;
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

        /**
         * Draw a section of the texture.
         *
         * @param float x    The x position of the texture.
         * @param float y    The y position of the texture.
         *
         * @return raylib::Texture&
         */
        void DrawAllTiles(float xp = 0, float yp = 0)
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


        float scale;

    private:
        raylib::Texture texture;
        int width;
        int height;
        float tileSize;
        Color tint = WHITE;
};

#endif
