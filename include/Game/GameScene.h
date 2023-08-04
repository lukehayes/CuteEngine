#ifndef GAME_GAMESCENE_H
#define GAME_GAMESCENE_H

#include "CT/Scene/Scene.h"

namespace Game
{
class GameScene : public CT::Scene::Scene
{
public:
	GameScene();

	//GameScene(GameScene &&) = default;
	//GameScene(const GameScene &) = default;
	//GameScene &operator=(GameScene &&) = default;
	//GameScene &operator=(const GameScene &) = default;
	~GameScene();

	void update(double dt);

	void render();

private:
};
}

#endif // !GAME_GAMESCENE_H
