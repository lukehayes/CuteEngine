#include "common/types.h"
#include "ECS/World.h"
#include "ECS/System/System.h"

float delta = 0.0;

int main() {

    game.init();

    ECS::World world;
    ECS::System::System system;

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        world.update(delta);

        ClearBackground(GRAY);
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

