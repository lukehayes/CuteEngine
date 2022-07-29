#include "raylib.h"
#include "game.h"
#include "entity/entity.h"
#include "entity/player.h"
#include "container/entity-container.h"

float delta = 0.0;

int main() {

	game.init();

	std::shared_ptr<Entity> e = std::make_shared<Entity>();
	entityContainer.add(e);

	std::shared_ptr<Entity> p = std::make_shared<Player>();
	entityContainer.add(p);

	entityContainer.fill(10);
	
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

