/** @file  Game/GameScene.h
 *
 * @brief A test GameScene class.
 * @namespace Game.
 * @author LDH.
 */
#ifndef GAME_GAMESCENE_H
#define GAME_GAMESCENE_H

#include "CT/Scene/Scene.h"

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
