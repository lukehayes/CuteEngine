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

    std::vector<ECS::Entity::Entity> entities;

    for(int i = 0; i <= 1000; i++)
    {
        ECS::Entity::Entity entity;
        std::shared_ptr<ECS::Component::Component> pos = std::make_shared<ECS::Component::PositionComponent>(GetRandomValue(10,400), GetRandomValue(10,400));
        std::shared_ptr<ECS::Component::Component> col = std::make_shared<ECS::Component::ColorComponent>(
                GetRandomValue(0.0,1.0),
                GetRandomValue(0.0,1.0),
                GetRandomValue(0.0,1.0)
        );
        entity.addComponent("Position", pos);
        entity.addComponent("Color", col);
        entities.push_back(entity);
    }

    ECS::Entity::Entity player;
    std::shared_ptr<ECS::Component::Component> pos = std::make_shared<ECS::Component::PositionComponent>(100.0,203.0);
    std::shared_ptr<ECS::Component::Component> col = std::make_shared<ECS::Component::ColorComponent>(0.5,1.0,0);

    player.addComponent("Position", pos);
    player.addComponent("Color", col);

    auto posComp = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(player.getComponent("Position"));
    auto colComp = std::static_pointer_cast<ECS::Component::ColorComponent>(player.getComponent("Color"));


    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        world.update(delta);

        ClearBackground(GRAY);
        BeginDrawing();

            for(auto &e : entities)
            {
                auto posComp = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(e.getComponent("Position"));
                auto colComp = std::dynamic_pointer_cast<ECS::Component::ColorComponent>(e.getComponent("Color"));
                DrawRectangle(posComp->x, posComp->y, 10,10, (Color){1,0,0});
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

