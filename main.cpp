#include "Game.h"

#include "ECS/Component.h"
#include "ECS/TransformComponent.h"

#include <cstdio>
#include <vector>
#include <array>

float delta = 0.0;

constexpr int MAX_ENTITIES = 3;

int main() {

    game.init();

    std::array<std::array<ECS::Component*, 3>, MAX_ENTITIES> entities;

    for(int i = 0; i <= MAX_ENTITIES - 1; i++)
    {
        // std::vector<ECS::Component*> components = entities.at(i);
        // components.at(0) = new ECS::TransformComponent(10,10, GetRandomValue(10,400), GetRandomValue(10,400));
        entities[i][0] = new ECS::TransformComponent(GetRandomValue(10,300), GetRandomValue(10,300), 10,10, PINK);
        entities[i][1] = nullptr;
        entities[i][2] = nullptr;
    }


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
        }


        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
