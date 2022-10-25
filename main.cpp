#include "ECS/Entity/Entity.h"
#include "ECS/Component/Component.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/System/PositionSystem.h"
#include "ECS/World.h"
#include <memory>

float delta = 0.0;

using ComponentPtr = std::shared_ptr<ECS::Component::Component>;
using PositionPtr = std::shared_ptr<ECS::Component::PositionComponent>;
using PositionComp = ECS::Component::PositionComponent;
using Entity = ECS::Entity::Entity;

int main() {

  game.init();

  ECS::World world;
  ECS::System::PositionSystem positionSystem;

  std::vector<ECS::Entity::Entity> entities;

  // FIXME Workout and refactor this.
  //
  /* == Temporary Working Solution ==================================== */
  ECS::Entity::Entity e(1);
  std::shared_ptr<ECS::Component::Component> posPtr = std::make_shared<ECS::Component::PositionComponent>(100,100,10,10);
  e.addComponent("Position", posPtr);
  std::shared_ptr<ECS::Component::PositionComponent> pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(e.getComponent("Position"));
  /* ================================================================== */

  float speed = 10.0;

  while (!WindowShouldClose()) {
    delta = GetFrameTime();
    world.update(delta);

    positionSystem.update(delta);

    ClearBackground(GRAY);
    BeginDrawing();
        DrawRectangle(10, 10, 10, 10, BLACK);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
