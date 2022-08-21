#include "raylib.h"
#include "game.h"
#include "entity/entity.h"
#include "entity/player.h"
#include "container/entity-container.h"
#include "sprite/sprite.h"
#include <iostream>

float delta = 0.0;

int main() {

	game.init();

	std::shared_ptr<Entity> e = std::make_shared<Entity>();
	std::shared_ptr<Entity> a = std::make_shared<Entity>(Vector2(400,400), Vector2(20,20), 130);
	// Sprite sprite("assets/bernie.png");
	std::cout << entityContainer.size() << std::endl;
	
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

