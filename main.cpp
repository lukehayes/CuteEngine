#include "raylib.h"
#include "raylib-cpp.hpp"
#include "Tileset.h"
#include "Sprite.h"
#include "Entity.h"
#include "Collision.h"
#include "CollisionRect.h"
#include <iostream>

float delta = 0.0;
float speed = 10.0;
float size = 30.0;
float MAX = 10.0;

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    raylib::Window window(screenWidth, screenHeight, "RayEngine!");

    SetTargetFPS(60);

    static float c = 0.0;

    Tileset ts("assets/8x8.png", 8, 4, 7,11);
    Sprite sp("assets/bernie.png", 300,300, 1, 180);

    float xp = 10.0f;
    float yp = 10.0f;

    Rectangle a = {(float)screenWidth / 2, (float)screenHeight / 2, size, size};
    Rectangle b = {150,120, size, size};
    Entity e(20,20, "assets/player.png");
    CollisionRect cr(100,200,100,100);

    Vector2 vel = {0,0};

    std::vector<CollisionRect> rects;

    for(int i = 0; i <= MAX - 1; i++)
    {
        CollisionRect r = {(float)GetRandomValue(0, 750), (float)GetRandomValue(0, 600), size, size};
        CollisionRect fr = {(float)i * 10, 580, size, size};
        rects.push_back(r);
        rects.push_back(fr);
    }

    while (!window.ShouldClose())
    {
        delta = GetFrameTime();
        c += 0.05;

        e.Update();

        if(IsKeyDown(KEY_A))
        {
            vel.x -= 1;
        }

        if(IsKeyDown(KEY_D))
        {
            vel.x += 1;
        }

        if(IsKeyDown(KEY_W))
        {
            vel.y -= 1;
        }

        if(IsKeyDown(KEY_S))
        {
            vel.y += 1;
        }

        e.x += vel.x * speed * delta;
        e.y += vel.y * speed * delta;


        if(Collision::AABB(a,b))
        {
            vel.x = -(vel.x / 2.0);
            vel.y = -(vel.y / 2.0);
        }

        for(auto r : rects)
        {
            if(e.colRect.CollidesWith(r))
            {
                vel.x = -(vel.x / 2);
                vel.y = -(vel.y / 2);

            }
        }
        //if(cr.CollidesWith(e.colRect))
        //{
            //vel.x = -(vel.x / 2);
            //vel.y = -(vel.y / 2);

        //}

        //for(auto r : rects)
        //{
            //if(Collision::AABB(a,r))
            //{
                //vel.x = -vel.x;
                //vel.y = -vel.y;
            //}
        //}

        BeginDrawing();
            window.ClearBackground({41, 30, 49});

            DrawRectangle(a.x, a.y, a.width, a.height, GREEN);
            DrawRectangle(b.x, b.y, b.width, b.height, RED);

            DrawRectangle(cr.rect.x, cr.rect.y, cr.rect.width, cr.rect.height, cr.color);

            e.Draw();
            DrawRectangleLines(e.colRect.rect.x, e.colRect.rect.y, e.colRect.rect.width, e.colRect.rect.height, e.colRect.color);


            for(auto r : rects)
            {
                DrawRectangle(r.rect.x, r.rect.y, r.rect.width, r.rect.height, BLUE);
            }

        EndDrawing();

    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

