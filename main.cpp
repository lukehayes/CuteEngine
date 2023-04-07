#include "Game.h"


float delta = 0.0;

int main() {

    game.init();

    while (!WindowShouldClose()) {
        delta = GetFrameTime();


        ClearBackground(GRAY);
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
