#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include "raylib.h"

struct Object
{
    int x;
    int y;
    int w;
    int h;
    int xDir;
    int yDir;
    int velX;
    int velY;
    int speed;
    Color color;
};


struct Object* CreateObject(int x, int y);
void DestroyObject(struct Object* obj);
void DrawObject(struct Object* o);
void UpdateObject(struct Object* o, float dt);
static void CheckEdgeCollisions(struct Object* o);

#endif // OBJECT_H
