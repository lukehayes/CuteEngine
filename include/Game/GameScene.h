/** @file  Game/GameScene.h
 *
 * @brief A test GameScene class.
 * @namespace Game.
 * @author LDH.
 */
#ifndef GAME_GAMESCENE_H
#define GAME_GAMESCENE_H

#include "CT/Scene/Scene.h"

// TODO Trying to implement a 'GameScene/Scene Tree' architecture this early
// in the project was a massive oversight and I need to pull back to
// work on the more essential parts of the code first. Will come
// back to this at a later stage.
namespace Game
{
	class GameScene : public CT::Scene::Scene
	{
	public:
		GameScene();

		GameScene(const Vector2& position, const Vector2& size, Color color);

		~GameScene();

		void update(double dt);

		void render();

	private:
	};
}

#endif // !GAME_GAMESCENE_H
