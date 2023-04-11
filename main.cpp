#include "Game.h"

#include "ECS/Component.h"
#include "ECS/TransformComponent.h"

#include "ECS/System/RenderSystem.h"

#include "common/types.h"

#include <cstdio>
#include <vector>
#include <array>

/*============================================================
// Useful Variables
============================================================*/
float delta = 0.0;

// Stack limit is 1000000;
// constexpr int MAX_ENTITIES = 100;


int main() {

    game.init();

    printf("Initializing %i Entities \n", MAX_ENTITIES);

    // Initialize entities
    for(int i = 0; i <= MAX_ENTITIES - 1; i++)
    {
        Color color = {
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(200,255)
        };

        int size = 1;

        entities[i][0] = new ECS::TransformComponent(GetRandomValue(100,game.width), GetRandomValue(100,game.height), size, size, color);
        entities[i][1] = nullptr;
        entities[i][2] = nullptr;
    }
    // --------------------------------------------------- 


    ECS::RenderSystem renderSystem;


    while (!WindowShouldClose()) {
        delta = GetFrameTime();
        
        for(auto e : entities)
        {
            ECS::TransformComponent* tc = dynamic_cast<ECS::TransformComponent*>(e[0]);
            tc->update(delta);
        }

        ClearBackground(BLACK);
        BeginDrawing();

            renderSystem.update(delta);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
