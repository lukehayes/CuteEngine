#ifndef TILESET_H
#define TILESET_H

#include "raylib.h"
#include "raylib-cpp.hpp"
#include <string>

class Tileset
{
    public:
        Tileset(const std::string& imageFile, int width = 8, int height = 12, float tileSize = 16, float scale = 3.0f);
        ~Tileset();

        /**
         * Draw the whole texutre.
         *
         * @param float x    The x position of the texture.
         * @param float y    The y position of the texture.
         *
         * @return raylib::Texture&
         */
        void Draw(float x = 0, float y = 0);

        /**
         * Draw a section of the texture.
         *
         * @param float x    The x position of the texture.
         * @param float y    The y position of the texture.
         *
         * @return raylib::Texture&
         */
        void DrawTile(float x = 0, float y = 0, float tileX = 0, float tileY = 0);

        /**
         * Draw a section of the texture.
         *
         * @param float x    The x position of the texture.
         * @param float y    The y position of the texture.
         *
         * @return raylib::Texture&
         */
        void DrawAllTiles(float xp = 0, float yp = 0);


        raylib::Texture texture;
        int width;
        int height;
        float tileSize;
        float scale;
        Color tint = WHITE;
};

#endif
