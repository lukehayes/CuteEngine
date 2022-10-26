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

int main() {

  game.init();

  ECS::System::PositionSystem positionSystem;
  positionSystem.required({"Position", "Color"});

  ECS::System::DrawSystem drawSystem;
  drawSystem.required({"Position", "Color"});

  // FIXME Work out and refactor this.
  //
  /* == Temporary Working Solution ==================================== */
  ECS::Entity::Entity e(1);
  ECS::Entity::Entity ee(2);
  std::shared_ptr<ECS::Component::Component> posPtr = std::make_shared<ECS::Component::PositionComponent>(100,100,10,10);
  std::shared_ptr<ECS::Component::Component> posPtr2 = std::make_shared<ECS::Component::PositionComponent>(200,300,10,10);
  std::shared_ptr<ECS::Component::Component> color  = std::make_shared<ECS::Component::ColorComponent>(50,100,100,255);

  e.addComponent("Position", posPtr);
  e.addComponent("Color", color);
  ee.addComponent("Position", posPtr2);
  ee.addComponent("Color", color);


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
    BeginDrawing();
      drawSystem.render();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
