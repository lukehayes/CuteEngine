#pragma once

#include "raylib.h"

struct Game
{
	int width         = 640;
	int height        = 480;
	const char* title = "Game";

	/**
	 * Initialize Raylib etc.
	 */
	void init();
};

extern Game game;


