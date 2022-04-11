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
            raylib::Rectangle src = {offset + tileSize * tileX, offset + tileSize * tileY, tileSize, tileSize};
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
        void DrawTiles(float x = 0, float y = 0, float tileX = 0, float tileY = 0)
        {
            static float offset = 0.0;
            raylib::Rectangle src = {offset + tileSize * tileX, offset + tileSize * tileY, tileSize, tileSize};
            raylib::Rectangle dest = {x * (tileSize * scale), y * (tileSize * scale), tileSize * scale, tileSize * scale};
            //
            //raylib::Rectangle dest = {x * (scale * tileSize), y * (scale * tileSize), tileSize * scale, tileSize * scale};
            for(int x = 0; x <= this->width - 1; x++)
            {
                for(int y = 0; y <= this->height - 1; y++)
                {
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
