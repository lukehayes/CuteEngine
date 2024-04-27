#ifndef CT_TEXTURE_FACTORY_H
#define CT_TEXTURE_FACTORY_H

#include "raylib.h"
#include "CT/Asset/Asset.h"

namespace CT::Factory
{
    class TextureFactory
    {
    public:

        TextureFactory()
        {
            // FIXME Causes segfault!!!
            //this->loadAssetsIntoGPUMemory();
        }

        void loadToTexturePtr(Texture2D* texture, const std::string& imagePath)
        {
            // FIXME Causes segfault!!!
            // 
            //std::string imageAsset = CT::Asset::Asset::getImage(imagePath);
            //printf("Loading texture to Texture2D*");
            //*texture = LoadTexture((imageAsset).c_str());
        }

        void unloadFromTexturePtr(Texture2D* texture)
        {
            printf("Unloading Texture Pointer \n");
            UnloadTexture(*texture);
        }
        
        /**
         * Load all of the default textures into the GPU.
         */
        void loadAssetsIntoGPUMemory()
        {
            // FIXME Causes segfault!!!
            //
            std::string imageAsset = CT::Asset::Asset::getImage("bernie.png");
            this->bernie = LoadTexture((imageAsset).c_str());
        }

        /**
         * Load all of the default textures into the GPU.
         */
        void unloadAssetsIntoGPUMemory()
        {
            UnloadTexture(this->bernie);
            printf("Unloaded bernie.png texture \n");
        }

        Texture2D bernie;
        Texture2D* testTexture;
    };
}

#endif // !CT_TEXTURE_FACTORY_H
