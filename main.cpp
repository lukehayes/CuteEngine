#include "Game.h"

#include "ECS/Component.h"
#include "ECS/TransformComponent.h"

#include "ECS/System/RenderSystem.h"
#include "ECS/System/MoveSystem.h"

#include "common/types.h"

#include <cstdio>
#include <vector>
#include <array>

// Stack limit is 1000000;
// constexpr int MAX_ENTITIES = 100;


int main() {

    game.init();
    game.deltaTime = 0.0;

    printf("Initializing %i Entities \n", MAX_ENTITIES);

    /*============================================================
    // Entity Initializtion
    ============================================================*/

    /**
     * Entity Array Layout:
     *
     * [0] Transform Component - Always defined
     * [1] Sprite Component    - Can be null
     * [2] Timer Component     - Can be null - Possible Map
     * [3] Sound Component     - Can be null - Possible Map
     */
    for(int i = 0; i <= MAX_ENTITIES - 1; i++)
    {
        Color color = {
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(10,255),
            (unsigned char)GetRandomValue(200,255)
        };

        int size = 10;

        entities[i][0] = new ECS::TransformComponent(GetRandomValue(100,game.width), GetRandomValue(100,game.height), size, size, color);
        entities[i][1] = nullptr;
        entities[i][2] = nullptr;
    }

    /*============================================================
    // System Initializtion
    ============================================================*/
    ECS::RenderSystem renderSystem;
    ECS::MoveSystem   moveSystem;

    while (!WindowShouldClose()) {
        game.deltaTime = GetFrameTime();

        moveSystem.update(game.deltaTime);
        renderSystem.update(BLACK, game.deltaTime);
    }

    CloseWindow();

    return 0;
}
