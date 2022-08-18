#include "game.h"

void Game::init()
{
	InitWindow(
			this->width,
			this->height,
			this->title
		  );

  SetTargetFPS(60);
	SetExitKey(KEY_Q);
}

Game game = {};
