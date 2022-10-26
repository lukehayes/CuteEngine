#pragma once

#include "raylib.h"

struct Game
{

	Game();

	/**
	 * Intialize Raylib, call raylib functions like SetFPS() etc.
	 */
	void init();

	int width;
	int height;
	const char* title;
};

extern Game game;


