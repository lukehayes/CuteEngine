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

        /**
        * Load a texture into GPU memory.
        *
        * @param const std::string& image
        *
        * @return std::shared_ptr<Texture2D>
        */
        static std::shared_ptr<Texture2D>
        loadToTexturePtr(const std::string& image)
        {

            // FIXME This can silently fail. If the path is wrong or the file
            // does not exists then NO ERRORS are reported at all
            // and it appears that it is working when it isnt.
            std::string imageAsset = Asset::Asset::getImage(image);
            std::shared_ptr<Texture2D> texture_ptr = std::make_shared<Texture2D>(LoadTexture(imageAsset.c_str()));
            return texture_ptr;
        }
    };
}

#endif // !CT_TEXTURE_FACTORY_H
