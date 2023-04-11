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

        entities[i][0] = new ECS::TransformComponent(GetRandomValue(10,game.width), GetRandomValue(10,game.height), 10,10, color);
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

            DrawRectangle(
                tc->position.x,
                tc->position.y,
                tc->size.x,
                tc->size.y,
                tc->color
            );

            tc->position.x += tc->dx * SPEED * delta;
            tc->position.y += tc->dy * SPEED * delta;


            
            if(
                tc->position.x < 10 || tc->position.x > (game.width - 20) ||
                tc->position.y < 10 || tc->position.y > (game.height - 20)
            )
            {
                tc->position.x = -tc->dx;
                tc->position.y = -tc->dy;

            }


        }


        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
