#pragma once

#include "raylib.h"

struct Game
{
	int width         = 1024;
	int height        = 768;
	const char* title = "Game";

	/**
	 * Initialize Raylib etc.
	 */
	void init();
};

extern Game game;


