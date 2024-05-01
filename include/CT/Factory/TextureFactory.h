#ifndef CT_TEXTURE_FACTORY_H
#define CT_TEXTURE_FACTORY_H

#include "raylib.h"
#include "CT/Asset/Asset.h"
#include <memory>

namespace CT::Factory
{  
    class TextureFactory
    {
    public:
        std::shared_ptr<Texture2D>
        loadToTexturePtr(const std::string& imagePath);
    };
}

#endif // !CT_TEXTURE_FACTORY_H
