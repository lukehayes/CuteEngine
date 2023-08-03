#include "Game/Game.h"
#include "CT/Common/Constants.h"

namespace Game
{
	Game::Game()
		: width(WINDOW_WIDTH),
		  height(WINDOW_HEIGHT),
		  title(GAME_TITLE),
		  deltaTime(0.0)
	{}

	void  
	Game::Game::init()
	{
		InitWindow(
			this->width,
			this->height,
			this->title
		);

		InitAudioDevice();

		SetTargetFPS(60);
		SetExitKey(KEY_Q);
	}
}
