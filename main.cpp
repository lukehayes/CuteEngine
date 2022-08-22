#include "raylib.h"
#include "game.h"
#include "entity/entity.h"
#include "bullet/bullet.h"
#include "entity/player.h"
#include "container/entity-container.h"
#include "sprite/sprite.h"
#include <iostream>

float delta = 0.0;

int main() {

	game.init();

	// std::shared_ptr<Entity> e = std::make_shared<Sprite>("assets/bernie.png", Vector2{ 100,111});
	std::shared_ptr<Entity> p = std::make_shared<Player>(Vector2{((float)game.width - 25)/ 2,((float)game.height - 25) / 2});
	std::shared_ptr<Entity> e = std::make_shared<Entity>(Vector2{200,500});
	std::shared_ptr<Entity> b = std::make_shared<Bullet>(Vector2{500,100}, e->position);

  while (!WindowShouldClose())
  {
    delta = GetFrameTime();

		entityContainer.update(delta);

		if(IsMouseButtonPressed(0))
		{
			std::shared_ptr<Entity> b = std::make_shared<Bullet>(Vector2{500,100}, GetMousePosition());
			entityContainer.add(b);
		}

		p->update(delta);
		b->update(delta);
		// e->update(delta);

		ClearBackground(GRAY);
		BeginDrawing();

		p->render();
		b->render();
		e->render();

		entityContainer.render();

    EndDrawing();
  }

	CloseWindow();

  return 0;
}

