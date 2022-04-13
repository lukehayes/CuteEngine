#ifndef COLLISION_H
#define COLLISION_H

#include "raylib.h"
            #include <iostream>

/**
 * Static helper functions to check for collisions.
 */
class Collision
{
    public:


        /**
         * Simple Axis Aligned Bounding Box collision.
         *
         * @param  Rectangle& a
         * @param  Rectangle& b
         * @return bool
         */
        static bool AABB(const Rectangle& a, const Rectangle& b)
        {
            return a.x < b.x + b.width &&
                   b.x < a.x + a.width &&
                   a.y < b.y + b.height &&
                   b.y < a.y + a.height;
        }

        static bool AABB2(Rectangle& a, Rectangle& b)
        {
            bool x_overlaps = (a.x < b.width) && (a.width > b.x);
            bool y_overlaps = (a.y < b.height) && (a.height > b.y);
            bool collision = x_overlaps && y_overlaps;
            return collision;
        }
};

#endif
