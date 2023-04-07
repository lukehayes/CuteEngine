#include "Game.h"

#include "ECS/Component.h"
#include "ECS/TransformComponent.h"

#include <vector>
#include <array>

float delta = 0.0;

constexpr int MAX_ENTITIES = 10;

int main() {

    game.init();

    std::array<std::array<ECS::Component*, 3>, MAX_ENTITIES> entities;

    for(int i = 0; i <= MAX_ENTITIES - 1; i++)
    {
        // std::vector<ECS::Component*> components = entities.at(i);
        // components.at(0) = new ECS::TransformComponent(10,10, GetRandomValue(10,400), GetRandomValue(10,400));
        entities[i][0] = new ECS::TransformComponent(1,1, GetRandomValue(10,400), GetRandomValue(10,400), RED);
        entities[i][1] = nullptr;
        entities[i][2] = nullptr;
    }


    while (!WindowShouldClose()) {
        delta = GetFrameTime();

        ClearBackground(GRAY);
        BeginDrawing();
        
        for(auto& e : entities)
        {
            for(auto& comp : e)
            {
                if(!comp) break;

                ECS::TransformComponent* c = dynamic_cast<ECS::TransformComponent*>(comp);

                DrawRectangle(
                        c->position.x,
                        c->position.y,
                        c->size.x,
                        c->size.y,
                        c->color
                        );
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
