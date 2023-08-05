#include "Game/GameScene.h"

#include "stdio.h"
#include <iostream>

namespace Game
{
	GameScene::GameScene(const Vector2& position, const Vector2& size, Color color)
		: CT::Scene::Scene(position, size, color)
	{}

	GameScene::GameScene() {}

	GameScene::~GameScene() {}

	void GameScene::update(double dt)
	{
		//this->position.x += 1 * this->speed * dt;
		for(auto child : this->children)
		{
			child->position.x = position.x + 100;
			child->position.y = position.y + 100;
			child->update(dt);
		}
	}

	void GameScene::render()
	{
        DrawRectangle(
			this->position.x,
			this->position.y,
			this->size.x,
			this->size.y,
			this->color
        );

		for(auto child : this->children)
		{
			child->render();
		}
	}
}



