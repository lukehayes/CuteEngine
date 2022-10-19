#include "common/types.h"
#include "ECS/World.h"
#include "ECS/System/System.h"
#include "ECS/Entity/Entity.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/Component/Component.h"
#include <memory>


float delta = 0.0;

using ComponentPtr = std::shared_ptr<ECS::Component::Component>;

int main() {

    game.init();

    ECS::World world;
    ECS::System::System system;
    
    ECS::Component::PositionComponent pos(100,100);

    ECS::Entity::Entity p;
    ComponentPtr pos = std::make_shared<ECS::Component::Component>(11.0,23.0)>

    p.addComponent("Position", pos);

    //std::pair<std::string, ECS::Component::Component> comp = p.getComponent("Position");

    //std::cout << comp.second->x << std::endl;

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        world.update(delta);

        ClearBackground(GRAY);
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

