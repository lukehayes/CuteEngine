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

	// std::shared_ptr<Entity> e = std::make_shared<Sprite>("assets/bernie.png", Vector2{ 100,111});
	std::shared_ptr<Entity> p = std::make_shared<Player>(Vector2{((float)game.width - 25)/ 2,((float)game.height - 25) / 2});

  while (!WindowShouldClose())
  {
    delta = GetFrameTime();

		p->update(delta);
		// e->update(delta);

		ClearBackground(GRAY);
		BeginDrawing();

		p->render();
		// e->render();

    EndDrawing();
  }

	CloseWindow();

  return 0;
}

