#include "Game.h"

	Game::Game()
		: width(800),
		  height(600),
		  title("Game Title")
	{}

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
