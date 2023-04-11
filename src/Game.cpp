#include "Game.h"

	Game::Game()
		: width(1920),
		  height(1080),
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

EntityArray entities = {};
