#include "Game/Game.h"
#include "CT/Common/Constants.h"
#include "CT/Common/Globals.h"

#include "CT/ECS/System/RenderSystem.h"
#include "CT/ECS/System/MoveSystem.h"
#include "CT/ECS/System/CollisionSystem.h"
#include "CT/ECS/System/TimerSystem.h"

#include "CT/ECS/Factory/EntityFactory.h"

int main() {

    SetTraceLogLevel(LOG_NONE);
    game.init();

    /*============================================================
    // Fill the entity array with entities
    ============================================================*/
    EntityArray ev = CT::ECS::GenerateEntities(MAX_ENTITIES);

    /*============================================================
    // System Initializtion
    ============================================================*/
    CT::ECS::RenderSystem renderSystem;
    renderSystem.entities = &ev ;

    CT::ECS::TimerSystem timerSystem;
    timerSystem.entities = &ev ;

    CT::ECS::MoveSystem   moveSystem;
    moveSystem.entities = &ev ;

    CT::ECS::CollisionSystem   collisionSystem;
    collisionSystem.entities = &ev ;


    while (!WindowShouldClose()) {
        game.deltaTime = GetFrameTime();

        moveSystem.update(game.deltaTime);
        //collisionSystem.update(game.deltaTime);
        timerSystem.update(game.deltaTime);
        renderSystem.update(BLACK, game.deltaTime);
    }

    CT::ECS::DestroyEntities(ev, MAX_ENTITIES);

    CloseWindow();

    return 0;
}
