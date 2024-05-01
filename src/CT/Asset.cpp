#include "CT/Asset/Asset.h"

namespace CT::Asset
{
    std::string Asset::getAssetPath()
    {
        return "assets";
    }

    std::string Asset::getImage(const std::string& image)
    {
        return Asset::getAssetPath() +  "/images/" + image + ".png";
    }

    std::string Asset::getFontPath() {
        return Asset::getAssetPath() + "/fonts";
    }

    std::string Asset::getSoundsPath() 
    {
        return Asset::getAssetPath() + "/sounds";
    }
}
