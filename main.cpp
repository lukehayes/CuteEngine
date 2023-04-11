#include "Game.h"

#include "ECS/Component.h"
#include "ECS/TransformComponent.h"

#include <cstdio>
#include <vector>
#include <array>

float delta = 0.0;

// Stack limit is 1000000;
constexpr int MAX_ENTITIES = 100;
constexpr int SPEED = 200;

int main() {

    game.init();

    printf("Initializing %i Entities \n", MAX_ENTITIES);

    // Initialize entities
    std::array<std::array<ECS::Component*, 3>, MAX_ENTITIES> entities;

    for(int i = 0; i <= MAX_ENTITIES - 1; i++)
    {
        Color color = {
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(200,255)
        };

        int size = GetRandomValue(2,20);

        entities[i][0] = new ECS::TransformComponent(GetRandomValue(10,game.width), GetRandomValue(10,game.height), size, size, color);
        entities[i][1] = nullptr;
        entities[i][2] = nullptr;
    }
    // --------------------------------------------------- 

    while (!WindowShouldClose()) {
        delta = GetFrameTime();
        

        ClearBackground(BLACK);
        BeginDrawing();


        for(auto e : entities)
        {
            ECS::TransformComponent* tc = dynamic_cast<ECS::TransformComponent*>(e[0]);

            tc->update(delta);

            DrawRectangle(
                tc->position.x,
                tc->position.y,
                tc->size.x,
                tc->size.y,
                tc->color
            );

        }


        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
