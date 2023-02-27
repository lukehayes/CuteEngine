#include "ECS/Entity/Entity.h"
#include "ECS/Component/Component.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/Component/ColorComponent.h"
#include "ECS/System/PositionSystem.h"
#include "ECS/System/DrawSystem.h"
#include "ECS/System/System.h"
#include "ECS/World.h"
#include <memory>

float delta = 0.0;

#if DEV_DEBUG == 1
#define LOG(x) (printf("LOG: %s \n", x))
#else
#define LOG(x)
#endif

/**
 * Draw lots of entities for testing.
 */
void drawLots(std::vector<ECS::Entity::Entity>& ent, int count = 100)
{
    for(int i = 0; i <= count; i++)
    {
        ECS::Entity::Entity e(10);

        int rx = GetRandomValue(20,300);
        int ry = GetRandomValue(20,300);
        int rv = GetRandomValue(-10,10);
        int rs = GetRandomValue(5,30);
        int r  = GetRandomValue(10,255);
        int g  = GetRandomValue(10,255);
        int b  = GetRandomValue(110,255);
        int a  = GetRandomValue(110,255);
        std::shared_ptr<ECS::Component::Component> color  = std::make_shared<ECS::Component::ColorComponent>(r,g,b,a);
        std::shared_ptr<ECS::Component::Component> pos = std::make_shared<ECS::Component::PositionComponent>((Vector2){rx,ry}, (Vector2){-rv,rv}, rs);

        e.addComponent("Position", pos);
        e.addComponent("Color", color);

        world.entities.push_back(e);
    }
}

int main() {

    game.init();

    ECS::System::PositionSystem positionSystem;
    positionSystem.required({"Position", "Color"});

    ECS::System::DrawSystem drawSystem;
    drawSystem.required({"Position", "Color"});

    // FIXME Work out and refactor this.
    //
    /* == Add Entities and Components Here =================================== */
    ECS::Entity::Entity e(1);
    ECS::Entity::Entity ee(2);

    std::shared_ptr<ECS::Component::Component> posPtr = std::make_shared<ECS::Component::PositionComponent>((Vector2){10,10}, (Vector2){10,10});
    std::shared_ptr<ECS::Component::Component> posPtr2 = std::make_shared<ECS::Component::PositionComponent>((Vector2){200,90},(Vector2){10,10});
    std::shared_ptr<ECS::Component::Component> color  = std::make_shared<ECS::Component::ColorComponent>(50,50,100,255);

    e.addComponent("Position", posPtr);
    e.addComponent("Color", color);
    ee.addComponent("Position", posPtr2);
    ee.addComponent("Color", color);

    drawLots(world.entities, 10000);

    world.entities.push_back(e);
    world.entities.push_back(ee);

    // std::shared_ptr<ECS::Component::PositionComponent> pos = e.getComponent("Position");
    // std::shared_ptr<ECS::Component::PositionComponent> pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(e.getComponent("Position"));
    /* ======================================================================= */


    while (!WindowShouldClose()) {
        delta = GetFrameTime();
        world.update(delta);

        positionSystem.update(delta);

        ClearBackground(GRAY);
        BeginDrawing();
        drawSystem.render();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
