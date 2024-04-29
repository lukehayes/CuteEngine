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

        TextureFactory() {}

        static std::shared_ptr<Texture2D>
        loadToTexturePtr(const std::string& imagePath)
        {
            std::string imageAsset = CT::Asset::Asset::getImage(imagePath);
            const char* img_asset_path = imageAsset.c_str();

            std::shared_ptr<Texture2D> texture_ptr = std::make_shared<Texture2D>(LoadTexture(img_asset_path));

            return texture_ptr;
        }

    };
}

#endif // !CT_TEXTURE_FACTORY_H
