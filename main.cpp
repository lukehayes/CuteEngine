#include "raylib.h"
#include "game.h"
#include "entity/entity.h"
#include <vector>

float delta = 0.0;

int main() {

	game.init();

	std::vector<Entity> entities;

	for(int i = 0; i <= 100; i++)
	{
		Entity e;
		entities.push_back(e);
	}

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();

		for(auto &e : entities)
		{
			e.update(delta);
		}

		BeginDrawing();
			ClearBackground(GRAY);

			for(auto e : entities)
			{
				e.render();
			}

        EndDrawing();
    }

	CloseWindow();

    return 0;
}

