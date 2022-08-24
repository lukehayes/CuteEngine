#include "common/types.h"
#include "container/typed-container.h"

float delta = 0.0;

int main() {

    game.init();

    std::shared_ptr<Entity> p = std::make_shared<Player>(Vector2{((float)game.width - 25)/ 2,((float)game.height - 25) / 2});

    TypedContainer<Bullet> bullets;

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();


        if(IsMouseButtonDown(0))
        {
            std::shared_ptr<Bullet> b = std::make_shared<Bullet>(p->position, GetMousePosition());
            bullets.add(b);
        }

        p->update(delta);
        bullets.update(delta);

        ClearBackground(GRAY);
        BeginDrawing();
            p->render();
            bullets.render();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

