#include "raylib.h"
#include "raylib-cpp.hpp"
#include "Tileset.h"
#include "Sprite.h"
#include "Entity.h"
#include "Math.h"
#include "Game.h"
#include "PlayState.h"
#include <memory>
#include <iostream>


float delta = 0.0;

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    raylib::Window window(screenWidth, screenHeight, "RayEngine!");

    std::shared_ptr<State> ps = std::make_shared<PlayState>();
    game.addState(ps);

    SetTargetFPS(60);

    static float c = 0.0;
    Entity e(10,300, "assets/player.png");

    // Initialize all of the instances before the loop.
    game.Create();

    while (!window.ShouldClose())
    {
        delta = GetFrameTime();
        c += 0.05;

        game.Update(delta);
        game.Draw();

        //BeginDrawing();
            //window.ClearBackground({41, 30, 49});
            //DrawRectangleLines(e.colRect.rect.x, e.colRect.rect.y, e.colRect.rect.width, e.colRect.rect.height, e.colRect.color);
        //EndDrawing();
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

