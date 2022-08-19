#include "entity/entity.h"
#include <string>

class Sprite : public Entity
{
public:
  Sprite(const std::string imagePath);

  Sprite(Sprite &&) = default;
  Sprite(const Sprite &) = default;
  Sprite &operator=(Sprite &&) = default;
  Sprite &operator=(const Sprite &) = default;
  ~Sprite();

  virtual void render();
	virtual void update(double dt);


private:
  std::string imagePath;
  Image imageObject;
  
};

Sprite::Sprite(const std::string imagePath)
    : imagePath(imagePath),
    imageObject(LoadImage(imagePath.c_str()))
{
}

Sprite::~Sprite()
{
  UnloadImage(this->imageObject);
}

void Sprite::render() 
{
}

void Sprite::update(double dt)
{
}

