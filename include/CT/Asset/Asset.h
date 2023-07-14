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
        static std::string getAssetPath();

        /**
         * Get the a full path to an image.
         *
         * @param const std::string& image.
         *
         * @return std::string.
         */
        static std::string getImage(const std::string& image);

        /**
         * Get the path to the fonts directory.
         *
         * @return std::string.
         */
        static std::string getFontPath();

        /**
         * Get the path to the sounds directory.
         *
         * @return std::string.
         */
        static std::string getSoundsPath();

    };
}

#endif // !CT_TEXTURE_FACTORY_H
