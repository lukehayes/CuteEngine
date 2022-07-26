#include "raylib.h"
#include "game.h"
#include "entity/entity.h"
#include "entity/player.h"
#include "container/entity-container.h"

float delta = 0.0;

int main() {

	game.init();

	std::unique_ptr<Entity> e = std::make_unique<Entity>();
	entityContainer.add(e);

	std::unique_ptr<Entity> p = std::make_unique<Player>();
	entityContainer.add(p);


    while (!WindowShouldClose())
    {
        delta = GetFrameTime();

		entityContainer.update(delta);

		BeginDrawing();
			ClearBackground(GRAY);

			entityContainer.render();

        EndDrawing();
    }

	CloseWindow();

    return 0;
}

