#include "common/types.h"
#include "ECS/World.h"
#include "ECS/System/System.h"
#include "ECS/Entity/Entity.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/Component/ColorComponent.h"
#include "ECS/Component/Component.h"
#include <memory>


float delta = 0.0;

using ComponentPtr = std::shared_ptr<ECS::Component::Component>;
using PositionPtr = std::shared_ptr<ECS::Component::PositionComponent>;

int main() {

    game.init();

    ECS::World world;
    ECS::System::System system;
    
    ECS::Entity::Entity p;
    std::shared_ptr<ECS::Component::Component> pos = std::make_shared<ECS::Component::PositionComponent>(11.0,23.0);
    std::shared_ptr<ECS::Component::Component> col = std::make_shared<ECS::Component::ColorComponent>(0.5,1.0,0);

    p.addComponent("Position", pos);
    p.addComponent("Color", col);

    auto posComp = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(p.getComponent("Position"));
    auto colComp = std::dynamic_pointer_cast<ECS::Component::ColorComponent>(p.getComponent("Color"));

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

