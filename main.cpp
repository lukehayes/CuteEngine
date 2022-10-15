#include "common/types.h"
<<<<<<< Updated upstream
#include "container/typed-container.h"
=======
#include "ECS/World.h"
#include "ECS/System.h"

>>>>>>> Stashed changes

float delta = 0.0;

int main() {

    game.init();

<<<<<<< Updated upstream
=======
    ECS::World world;
    ECS::System system;

>>>>>>> Stashed changes
    while (!WindowShouldClose())
    {
        delta = GetFrameTime();

<<<<<<< Updated upstream
        ClearBackground(GRAY);
=======
        world.update(delta);

        ClearBackground(BLACK);
>>>>>>> Stashed changes
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

