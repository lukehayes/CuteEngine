#include "CT/Factory/TextureFactory.h"
#include <iostream>
#include <raylib.h>

namespace CT::Factory
{
    TextureFactory::TextureFactory() {}

    TextureFactory::~TextureFactory() {}

    void 
    TextureFactory::destroyTexturePointers()
    {
        for(int i = 0; i <= 10 - 1; i++)
        {
            UnloadTexture(this->textures[i]);
        }
        
        TraceLog(LOG_DEBUG, "Textures unloaded from texture factory.") ;
    }

    void 
    TextureFactory::loadTexturePointers()
    {
        std::string assets = CT::Asset::Asset::getAssetPath();
        Texture2D spritesheet = LoadTexture(("../assets/images/monochrome_tilemap_transparent.png"));
        this->textures[0] = spritesheet;
    }
        
}

