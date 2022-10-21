#include "common/types.h"
#include "ECS/World.h"
#include "ECS/System/PositionSystem.h"
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
    ECS::System::PositionSystem positionSystem;

    std::vector<ECS::Entity::Entity> entities;
    std::vector<std::shared_ptr<ECS::Component::PositionComponent>> positionComponents;

    for(int i = 0; i <= 10; i++)
    {
        ECS::Entity::Entity e(i);
        std::shared_ptr<ECS::Component::PositionComponent> pos = std::make_shared<ECS::Component::PositionComponent>(GetRandomValue(10,400), GetRandomValue(10,400), GetRandomValue(-100,100), GetRandomValue(-100,100));
        pos->entity_id = e.entity_id;
        positionSystem.components.push_back(pos);
    }

    //for(int i = 0; i <= 10; i++)
    //{
        //ECS::Entity::Entity entity(i);
        //std::shared_ptr<ECS::Component::Component> pos = std::make_shared<ECS::Component::PositionComponent>(GetRandomValue(10,400), GetRandomValue(10,400));
        //std::shared_ptr<ECS::Component::Component> col = std::make_shared<ECS::Component::ColorComponent>(
                //GetRandomValue(100,255),
                //GetRandomValue(100,255),
                //GetRandomValue(100,255),
                //GetRandomValue(100,255)
        //);

        //entity.addComponent("Position", pos);
        //entity.addComponent("Color", col);
        //entities.push_back(entity);
    //}

    float speed = 10.0;

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        world.update(delta);


        positionSystem.update(delta);

        ClearBackground(GRAY);
        BeginDrawing();
            DrawRectangle(10,10,10,10, BLUE);

            //for(auto pos : positionComponents)
            //{
                ////auto posComp = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(e.getComponent("Position"));
                ////auto colComp = std::dynamic_pointer_cast<ECS::Component::ColorComponent>(e.getComponent("Color"));

                //pos->x += GetRandomValue(-110,100) * delta;
                //pos->y += GetRandomValue(-100,100) * delta;


                //DrawRectangle(
                    //pos->x,
                    //pos->y,
                    //10,10,
                    //BLACK
                //);
            //}

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

