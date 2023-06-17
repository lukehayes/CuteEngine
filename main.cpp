#include "Game.h"
#include "Common/Constants.h"
#include "Common/Globals.h"

#include "ECS/System/RenderSystem.h"
#include "ECS/System/MoveSystem.h"
#include "ECS/System/CollisionSystem.h"

#include "ECS/Factory/EntityFactory.h"

int main() {

    SetTraceLogLevel(LOG_NONE);
    game.init();

    EntityArray ev = ECS::GenerateEntities(MAX_ENTITIES);

    /*============================================================
    // System Initializtion
    ============================================================*/
    ECS::RenderSystem renderSystem;
    renderSystem.entities = &ev ;


    ECS::MoveSystem   moveSystem;
    moveSystem.entities = &ev ;

    ECS::CollisionSystem   collisionSystem;
    collisionSystem.entities = &ev ;


    while (!WindowShouldClose()) {
        game.deltaTime = GetFrameTime();

        moveSystem.update(game.deltaTime);
        //collisionSystem.update(game.deltaTime);
        renderSystem.update(BLACK, game.deltaTime);
    }

    ECS::DestroyEntities(ev, MAX_ENTITIES);

    CloseWindow();

    return 0;
}
