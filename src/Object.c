#include "Object.h"
#include "raylib.h"
#include <stdlib.h>
#include <math.h>


struct Object* CreateObject(int x, int y)
{
    struct Object* obj = malloc(sizeof(struct Object));
    obj->x = x;
    obj->y = y;
    obj->w = 10;
    obj->h = 10;
    obj->xDir = -1;
    obj->yDir = -1;
    obj->speed = 5;
    obj->color = WHITE;

    return obj;
}

void DestroyObject(struct Object* obj)
{
    free(obj);
}

void DrawObject(struct Object* o)
{
    DrawRectangle(o->x, o->y, o->w, o->h, o->color);
}

void UpdateObject(struct Object* o, float dt)
{
    o->x += o->xDir * (o->speed);
    o->y += o->yDir * (o->speed);
    CheckEdgeCollisions(o);
}

static void CheckEdgeCollisions(struct Object* o)
{
    if(o->x > (800 - o->w) || o->x < 1)
    {

        o->xDir = -o->xDir;
        o->color = BLUE;
    }

    if(o->y > (600 - o->h) || o->y < 1)
    {
        o->yDir = -o->yDir;
        o->color = PINK;
    }
}
