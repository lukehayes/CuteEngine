#include "CT/Factory/TextureFactory.h"
#include "CT/Common/Globals.h"


namespace CT::Factory 
{

TextureFactory::TextureFactory(const std::string& imagePath)
{
    std::string imageAsset = CT::Asset::Asset::getImage(imagePath);
    this->texture = LoadTexture(imageAsset.c_str());
}

TextureFactory::~TextureFactory()
{
    UnloadTexture(this->texture);
}


std::shared_ptr<Texture2D>
TextureFactory::loadToTexturePtr(const std::string& imagePath)
{
    std::string imageAsset = CT::Asset::Asset::getImage(imagePath);
    const char* img_asset_path = imageAsset.c_str();

    std::shared_ptr<Texture2D> texture_ptr = std::make_shared<Texture2D>(LoadTexture(img_asset_path));

    return texture_ptr;
}
}


