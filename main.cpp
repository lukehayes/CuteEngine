#include "raylib.h"
#include <stdio.h>

float delta = 0.0;

int main() {
    int screenWidth = 800;
    int screenHeight = 600;
    SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        delta = GetFrameTime();
        c += 0.05;
    }


    return 0;
}

