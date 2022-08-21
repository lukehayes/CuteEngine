#pragma once
#include "entity/entity.h"
#include <raylib.h>
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

  void createEntityPtr();


private:
  std::string imagePath;
  Texture2D   texture;
  
};

