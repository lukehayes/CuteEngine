#ifndef CT_TEXTURE_FACTORY_H
#define CT_TEXTURE_FACTORY_H

#include "raylib.h"
#include "Asset/Asset.h"

namespace CTFactory
{
    class TextureFactory
    {
    public:

        TextureFactory()
        {
            this->loadAssetsIntoGPUMemory();
        }
        
        /**
         * Load all of the default textures into the GPU.
         */
        void loadAssetsIntoGPUMemory()
        {
            std::string assets = CTAsset::Asset::getAssetPath();
            printf("Assets: %s \n", assets.c_str());
            this->bernie = LoadTexture((assets + "/bernie.png").c_str());
        }

        /**
         * Load all of the default textures into the GPU.
         */
        void unloadAssetsIntoGPUMemory()
        {
            UnloadTexture(this->bernie);
            printf("Unloaded bernie texture");
        }

        Texture2D bernie;

    };
}

#endif // !CT_TEXTURE_FACTORY_H
