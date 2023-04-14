#include "Game.h"
#include "Common/Constants.h"
#include "Common/Globals.h"

#include "ECS/System/RenderSystem.h"
#include "ECS/System/MoveSystem.h"
#include "ECS/Factory/EntityFactory.h"
#include <stdio.h>

int main() {

    game.init();
    game.deltaTime = 0.0;

    EntityVector ev = ECS::GenerateEntities(MAX_ENTITIES);

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

    ECS::DestroyEntities(ev, MAX_ENTITIES);

    CloseWindow();

    return 0;
}
