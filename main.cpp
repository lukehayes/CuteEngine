#include "ECS/Entity/Entity.h"
#include "ECS/Component/Component.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/System/PositionSystem.h"
#include "ECS/System/System.h"
#include "ECS/World.h"
#include <memory>

float delta = 0.0;

int main() {

  game.init();

  ECS::System::PositionSystem positionSystem;
  positionSystem.required({"Position"});

  // FIXME Work out and refactor this.
  //
  /* == Temporary Working Solution ==================================== */
  ECS::Entity::Entity e(1);
  ECS::Entity::Entity ee(2);
  std::shared_ptr<ECS::Component::Component> posPtr = std::make_shared<ECS::Component::PositionComponent>(100,100,10,10);
  std::shared_ptr<ECS::Component::Component> posPtr2 = std::make_shared<ECS::Component::PositionComponent>(200,300,10,10);

  e.addComponent("Position", posPtr);
  ee.addComponent("Position", posPtr2);

  world.entities.push_back(e);
  world.entities.push_back(ee);

  // std::shared_ptr<ECS::Component::PositionComponent> pos = e.getComponent("Position");
  // std::shared_ptr<ECS::Component::PositionComponent> pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(e.getComponent("Position"));
  /* ================================================================== */
    

  while (!WindowShouldClose()) {
    delta = GetFrameTime();
    world.update(delta);

    positionSystem.update(delta);

    ClearBackground(GRAY);
        std::shared_ptr<ECS::Component::PositionComponent> pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(e.getComponent("Position"));

        for(auto e : world.entities)
        {
            std::shared_ptr<ECS::Component::PositionComponent> pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(e.getComponent("Position"));
            DrawRectangle(pos->x, pos->y, 30,30, GREEN);
        }

    BeginDrawing();
        
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
