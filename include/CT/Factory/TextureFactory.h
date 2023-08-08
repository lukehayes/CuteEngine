#ifndef CT_TEXTURE_FACTORY_H
#define CT_TEXTURE_FACTORY_H

#include "raylib.h"
#include "CT/Asset/Asset.h"

namespace CT::Factory
{
    class TextureFactory
    {
    public:

        TextureFactory();
        ~TextureFactory();
        void loadTexturePointers();
        void destroyTexturePointers();

        Texture2D textures[10];
    };
}

#endif // !CT_TEXTURE_FACTORY_H
