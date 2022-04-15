#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"
#include "CollisionRect.h"

class Entity
{
public:
    Entity(float x, float y, const std::string& filename)
        : x(10),
          y(10),
          sprite(filename, x,y),
          colRect(x,y)
    {}

    ~Entity(){}


    void Update()
    {
        sprite.x = x;
        sprite.y = y;
        colRect.rect.x = x;
        colRect.rect.y = y;
        colRect.rect.width = sprite.texture.GetWidth() * sprite.scale;
        colRect.rect.height = sprite.texture.GetHeight() * sprite.scale;
    }


    void Draw()
    {
        this->sprite.Draw(x, y);
    }

    float x;
    float y;
    Sprite sprite;
    CollisionRect colRect;
    bool isMoving = false;
};

#endif
