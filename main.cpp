#include "ECS/Entity/Entity.h"
#include "ECS/Component/Component.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/System/PositionSystem.h"
#include "ECS/World.h"
#include <memory>

float delta = 0.0;
//
// class A
// {
//   public:
//     A(int x) : x(x) {}
//     int x;
// };
//
// class B : public A
// {
//   public:
//     B(int x) : A(x) {}
//     int x;
// };

int main() {

  game.init();

  // std::shared_ptr<A> base = std::make_shared<A>(1);
  // std::shared_ptr<A> child = std::make_shared<B>(2);
  // std::cout << base->x << std::endl;
  // std::cout << child->x << std::endl;


  ECS::World world;
  ECS::System::PositionSystem positionSystem;

  std::vector<ECS::Entity::Entity> entities;

  // FIXME Work out and refactor this.
  //
  /* == Temporary Working Solution ==================================== */
  ECS::Entity::Entity e(1);
  std::shared_ptr<ECS::Component::Component> posPtr = std::make_shared<ECS::Component::PositionComponent>(100,100,10,10);
  e.addComponent("Position", posPtr);

  // std::shared_ptr<ECS::Component::PositionComponent> pos = e.getComponent("Position");
  std::shared_ptr<ECS::Component::PositionComponent> pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(e.getComponent("Position"));
  /* ================================================================== */

  std::cout << pos->x << std::endl;
  
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
