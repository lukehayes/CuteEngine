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

	std::shared_ptr<Entity> e = std::make_shared<Sprite>("assets/bernie.png", Vector2{ 100,111});
	std::shared_ptr<Entity> a = std::make_shared<Entity>(Vector2{ 40,40}, Vector2{100,200});

  while (!WindowShouldClose())
  {
    delta = GetFrameTime();

		// entityContainer.update(delta);
		a->update(delta);
		e->update(delta);

		ClearBackground(GRAY);
		BeginDrawing();

		// entityContainer.render();

		a->render();
		e->render();

    EndDrawing();
  }

	CloseWindow();

  return 0;
}

