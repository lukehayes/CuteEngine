#include "Game/GameScene.h"

#include "stdio.h"

namespace Game
{
	GameScene::GameScene()
	{
	}

	GameScene::~GameScene()
	{
	}

	void GameScene::update(double dt)
	{
		printf("Updating Game Scene: %f \n", dt);
	}

	void GameScene::render()
	{
		printf("Rendering Game Scene: %f \n");
	}
}



