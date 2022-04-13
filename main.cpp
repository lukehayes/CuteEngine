#include "raylib.h"
#include "raylib-cpp.hpp"
#include "Tileset.h"
#include "Sprite.h"
#include <iostream>

float delta = 0.0;

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    raylib::Window window(screenWidth, screenHeight, "RayEngine!");

    SetTargetFPS(60);

    static float c = 0.0;

    Tileset ts("assets/8x8.png", 8, 4, 7,11);

    while (!window.ShouldClose())
    {
        delta = GetFrameTime();
        c += 0.05;
        BeginDrawing();
            window.ClearBackground(BLACK);
            ts.DrawTile(0,0, 3,3);
            ts.DrawTile(8,0, 3,3);
        EndDrawing();

    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

