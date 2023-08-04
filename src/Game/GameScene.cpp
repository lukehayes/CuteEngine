#include "Game/GameScene.h"

#include "stdio.h"

namespace Game
{
	GameScene::GameScene(Vector2& position, Vector2& size, Color color)
		CT::Scene::Scene(position, size, color) {}

	GameScene::GameScene() {}

	GameScene::~GameScene() {}

	void GameScene::update(double dt)
	{
		printf("Updating Game Scene: %f \n", dt);
		this->position.x += 1 * this->speed * dt;
	}

	void GameScene::render()
	{
		printf("Rendering Game Scene: %f \n");
          DrawRectangle(
              this->position.x,
              this->position.y,
              this->size.x,
              this->size.y,
              this->color
            );
	}
}



