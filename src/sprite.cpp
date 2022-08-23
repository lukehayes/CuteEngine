#include "sprite/sprite.h"
#include<cmath>
#include "container/entity-container.h"

Sprite::Sprite(const std::string imagePath, const Vector2& position)
	: Entity(position, {50,50}, GetRandomValue(10,100)),
      texture(LoadTexture(imagePath.c_str()))
{
    // this->createEntityPtr();
	std::shared_ptr<Entity> e = std::make_shared<Sprite>(*this);
	entityContainer.add(e);

	this->rect.rect.width = texture.width;
	this->rect.rect.height = texture.height;
}

Sprite::~Sprite()
{
  UnloadTexture(this->texture);
}

void Sprite::render() 
{
    DrawTexture(
        texture,
        position.x,
        position.y,
        WHITE
    );
}

void Sprite::update(double dt)
{
	static float c = 0.0;
	c+= 0.01;
	position.x += std::cos(c) * speed * dt;
	position.y += std::sin(c) * speed * dt;
}

void Sprite::createEntityPtr()
{
	std::shared_ptr<Entity> e = std::make_shared<Sprite>(*this);
	entityContainer.add(e);
}
