#include "Game/Game.h"
#include "CT/Common/Constants.h"
#include "CT/Common/Globals.h"

#include "CT/ECS/System/RenderSystem.h"
#include "CT/ECS/System/MoveSystem.h"
#include "CT/ECS/System/CollisionSystem.h"
#include "CT/ECS/System/TimerSystem.h"

#include "CT/ECS/Factory/EntityFactory.h"

#include "Game/GameScene.h"

#include "CT/Core/CTBasic.h"

int main() {

    SetTraceLogLevel(LOG_NONE);
    game.init();

    /*============================================================
    // Fill the entity array with entities
    ============================================================*/
    EntityArray ev = CT::ECS::GenerateEntities(MAX_ENTITIES);

    std::vector<Game::GameScene> scenes;
    std::vector<Color> colors { RED, BLUE, GREEN };


    for (int i = 0; i <= 2; i++) {
        Game::GameScene gs({
            {GetRandomValue(10,500), GetRandomValue(10,500)},
            {GetRandomValue(10,500), GetRandomValue(10,500)},
            colors[GetRandomValue(0,colors.size())]
        });

        scenes.push_back(gs);
    }


    Game::GameScene gs1;
    Game::GameScene gs2;
    gs2.position.x = 300;
    gs2.position.y = 300;
    gs2.color = BLUE;

    CT::Core::CTBasic b1({100,100}, {20,200}, RED);
    CT::Core::CTBasic b2({10,10}, {120,20}, BLUE);



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

        for(auto s : scenes)
        {
            s.update(game.deltaTime);
        }

        ClearBackground(BLACK);
        BeginDrawing();
            for(auto s : scenes)
            {
                s.render();
            }
        EndDrawing();

        //moveSystem.update(game.deltaTime);
        //collisionSystem.update(game.deltaTime);
        //timerSystem.update(game.deltaTime);
        //renderSystem.update(BLACK, game.deltaTime);
    }

    CT::ECS::DestroyEntities(ev, MAX_ENTITIES);

    CloseWindow();

    return 0;
}
