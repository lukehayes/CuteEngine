#include "raylib.h"
#include "raylib-cpp.hpp"
#include "Tileset.h"
#include "Sprite.h"

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    raylib::Window window(screenWidth, screenHeight, "raylib-cpp - basic window");
    raylib::Texture logo("assets/bernie.png");

    SetTargetFPS(60);

    static float c = 0.0;

    Tileset ts("assets/monochrome_tilemap_transparent.png");
    Sprite sp("assets/bernie.png");


    while (!window.ShouldClose())
    {
        c += 0.05;

        BeginDrawing();

        //ts.Draw(200,200);

        //sp.Draw(100,100);
        ts.DrawTile(100,100,c,1);
        window.ClearBackground(BLACK);

        // Object methods.
        //logo.Draw(
            //(std::cos(c) * 100)  + screenWidth / 2 - logo.GetWidth() / 2,
            //(std::sin(c) * 100) + screenHeight / 2 - logo.GetHeight() / 2);
        //DrawText("Bernie says, build that f*****g game!", 190, 100, 20, LIGHTGRAY);
        EndDrawing();

    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

