#pragma once

#include "raylib.h"
#include "CT/Common/Types.h"

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

	double deltaTime;
};

