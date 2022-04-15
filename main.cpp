#include "raylib.h"
#include "raylib-cpp.hpp"
#include "Tileset.h"
#include "Sprite.h"
#include "Entity.h"
#include "Collision.h"
#include "CollisionRect.h"
#include "Math.h"
#include <iostream>

float delta = 0.0;
float speed = 10.0;
float size = 30.0;
float MAX = 10.0;
float MAX_SPEED = 10.0f;

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    raylib::Window window(screenWidth, screenHeight, "RayEngine!");

    SetTargetFPS(60);

    static float c = 0.0;

    float xp = 10.0f;
    float yp = 10.0f;

    Rectangle a = {(float)screenWidth / 2, (float)screenHeight / 2, size, size};
    Rectangle b = {150,120, size, size};
    Entity e(10,300, "assets/player.png");
    Vector2 vel{0,0};

    while (!window.ShouldClose())
    {
        delta = GetFrameTime();
        c += 0.05;

        e.Update();

        //if(IsKeyDown(KEY_W))
        //{
            //vel.y -= 1;
            //e.isMoving = true;
        //}else
        //{
            //e.isMoving = false;
        //}

        //if(IsKeyDown(KEY_S))
        //{
            //vel.y += 1;
            //e.isMoving = true;
        //}else
        //{
            //e.isMoving = false;
        //}

        //if(IsKeyDown(KEY_A))
        //{
            //vel.x -= 1;
            //e.isMoving = true;
        //}else 
        //{
            //e.isMoving = false;
        //}

        if(IsKeyDown(KEY_D))
        {
            vel.x += 1;
            e.isMoving = true;
        }else
        {
            e.isMoving = false;
            vel.x -= 10.01;
        }

        if(!e.isMoving)
        {
            static int c = 0;
            std::cout << "Not Moving " << c << std::endl;
            c++;
            //vel.x -= 0.01;
            //vel.y -= 0.01;

            if(vel.x < 0)
            {
                vel.x = 0;
            }

            if(vel.y < 0)
            {
                vel.y = 0;
            }
        }

        std::cout << "X " << vel.x << " Y " << vel.y << std::endl;

        e.x += vel.x * speed * delta;
        e.y += vel.y * speed * delta;

        BeginDrawing();
            window.ClearBackground({41, 30, 49});

            e.Draw();
            DrawRectangleLines(e.colRect.rect.x, e.colRect.rect.y, e.colRect.rect.width, e.colRect.rect.height, e.colRect.color);

        EndDrawing();
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

