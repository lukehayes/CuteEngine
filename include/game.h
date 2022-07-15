#pragma once

#include "raylib.h"
#include <string>

struct Game
{
	int width         = 640;
	int height        = 480;
	std::string title = "Game";

	/**
	 * Initialize Raylib etc.
	 */
	void init()
	{
		InitWindow(
			this->width,
			this->height,
			this->title.c_str()
		);

    	SetTargetFPS(60);
	}
};

extern Game game;


