#ifndef CT_ASSET_H
#define CT_ASSET_H

#include "raylib.h"
#include <string>

namespace CTAsset
{
    /**
     * Class contains helper functions for getting paths to assets etc.
     */
    class Asset
    {
    public:

        /**
         * Get the base path to the assets directory.
         *
         * @return std::string.
         */
        static std::string getAssetPath()
        {
            return "../assets";
        }

        /**
         * Get the path to the fonts directory.
         *
         * @return std::string.
         */
        static std::string getFontPath()
        {
            return Asset::getAssetPath() + "/fonts";
        }

        /**
         * Get the path to the sounds directory.
         *
         * @return std::string.
         */
        static std::string getSoundsPath() 
        {
            return Asset::getAssetPath() + "/sounds";
        }

    };
}

#endif // !CT_TEXTURE_FACTORY_H
