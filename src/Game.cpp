#include "Game.h"
#include "common/Constants.h"

Game::Game()
	: width(WINDOW_WIDTH),
	  height(WINDOW_HEIGHT),
	  title(GAME_TITLE)
{}

void Game::init()
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
