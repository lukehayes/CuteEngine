#ifndef COLLISION_RECT_H
#define COLLISION_RECT_H

#include "raylib.h"
#include "raylib-cpp.hpp"
#include "Collision.h"

class CollisionRect
{
    public:
        CollisionRect(float x = 0, float y = 0, float width = 16, float height = 16) : rect(x,y,width, height)
        {}

        /**
         * Check if this CollisionRect collides with another.
         *
         * @param const CollisionRect& otherRect.
         *
         * @return bool
         */
        bool CollidesWith(const CollisionRect& otherRect)
        {
            return Collision::AABB(this->rect, otherRect.rect);
        }

        raylib::Rectangle rect;
        Color color = RED;
};

#endif
