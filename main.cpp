#include "Game.h"
#include "Common/Constants.h"
#include "Common/Globals.h"

#include "ECS/Component/Component.h"
#include "ECS/Component/TransformComponent.h"
#include "ECS/Component/SoundComponent.h"

#include "ECS/System/RenderSystem.h"
#include "ECS/System/MoveSystem.h"
#include <stdio.h>

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

        entities[i][TRANSFORM_COMPONENT_INDEX] = new ECS::TransformComponent(GetRandomValue(100,game.width), GetRandomValue(100,game.height), size, size, color);
        entities[i][1] = nullptr;
        entities[i][2] = nullptr;
        entities[i][SOUND_COMPONENT_INDEX] = new ECS::SoundComponent("../assets/sounds/blip.wav");
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

    // TODO Cheeky memory allocation cleanup.
    for(int i = 0; i <= MAX_ENTITIES - 1; i++)
    {
        auto* tc = dynamic_cast<ECS::TransformComponent*>(entities[i][TRANSFORM_COMPONENT_INDEX]);
        auto* sc = dynamic_cast<ECS::SoundComponent*>(entities[i][SOUND_COMPONENT_INDEX]);

        delete tc;
        tc = nullptr;
        printf("Deleted Transform Component %i\n", i);

        delete sc;
        sc = nullptr;
        printf("Deleted Sound Component %i\n", i);

    }

    printf("All memory deleted \n");

    CloseWindow();

    return 0;
}
