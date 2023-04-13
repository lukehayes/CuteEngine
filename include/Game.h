#pragma once

#include "raylib.h"
#include "Common/Types.h"

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

// Make the game object available throughout the codebase
extern Game game;


/*============================================================
// Helpful Global Externs (defined in Game.cpp)
============================================================*/
extern EntityArray entities;

