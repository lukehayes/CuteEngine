#include "raylib.h"
#include "game.h"

float delta = 0.0;

int main() {
    int screenWidth = 800;
    int screenHeight = 600;
	
	InitWindow(
		game.width,
		game.height,
		game.title.c_str()
	);


    SetTargetFPS(60);

    while (WindowShouldClose())
    {
        delta = GetFrameTime();
    }


    return 0;
}

