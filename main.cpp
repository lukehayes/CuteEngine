#include "raylib.h"
#include "raylib-cpp.hpp"
#include "Tileset.h"
#include "Sprite.h"
#include "Collision.h"
#include "CollisionRect.h"
#include <iostream>

float delta = 0.0;
float speed = 10.0;
float size = 10.0;
float MAX = 1000.0;

class Entity
{
public:
    Entity(float x, float y) : cr(x,y,16,16), sprite("assets/player.png", 3.0){}
    void Draw() { sprite.Draw(x, y); }
    void Update() {
        cr.rect.x = this->x;
        cr.rect.y = this->y;
        std::cout << x << std::endl;
    }
    CollisionRect cr;
    Sprite sprite;
    Color color = PINK;
    float x;
    float y;
};

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    raylib::Window window(screenWidth, screenHeight, "RayEngine!");

    SetTargetFPS(60);

    static float c = 0.0;

    Tileset ts("assets/8x8.png", 8, 4, 7,11);
    Sprite sp("assets/bernie.png", 1, 180);

    float xp = 10.0f;
    float yp = 10.0f;

    Rectangle a = {(float)screenWidth / 2, (float)screenHeight / 2, size, size};
    Rectangle b = {150,120, size, size};
    CollisionRect cr(100,200,100,100);
    Entity e(screenWidth/2, screenHeight/2);

    Vector2 vel = {0,0};

    std::vector<Rectangle> rects;

    for(int i = 0; i <= MAX - 1; i++)
    {
        Rectangle r = {(float)GetRandomValue(0, 750), (float)GetRandomValue(0, 600), size, size};
        rects.push_back(r);
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

        if(cr.CollidesWith(e.cr))
        {
            vel.x = -(vel.x / 2);
            vel.y = -(vel.y / 2);
        }


        for(auto r : rects)
        {
            if(Collision::AABB(a,r))
            {
                vel.x = -vel.x;
                vel.y = -vel.y;
            }
        }


        BeginDrawing();
            window.ClearBackground(BLACK);

            //DrawRectangle(a.x, a.y, a.width, a.height, GREEN);
            DrawRectangle(b.x, b.y, b.width, b.height, RED);
            DrawRectangle(cr.rect.x, cr.rect.y, cr.rect.width, cr.rect.height, ORANGE);

            //DrawRectangleLines(e.cr.rect.x, e.cr.rect.y, e.cr.rect.width, e.cr.rect.height, PURPLE);
            e.Draw();


            //for(auto r : rects)
            //{
                //DrawRectangle(r.x, r.y, r.width, r.height, BLUE);
            //}

        EndDrawing();

    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

