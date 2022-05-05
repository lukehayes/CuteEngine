#ifndef OBJECT_H
#define OBJECT_H

#include "BasicObject.h"
#include "raylib.h"

class Object : public BasicObject
{
    public:
        Object();
        ~Object();

        Vector2 position;
        float health;
};

#endif
