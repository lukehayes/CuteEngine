#include "common/types.h"

float delta = 0.0;

int main() {

    game.init();

    std::shared_ptr<Entity> p = std::make_shared<Player>(Vector2{((float)game.width - 25)/ 2,((float)game.height - 25) / 2});

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();

        entityContainer.update(delta);

        if(IsMouseButtonPressed(0))
        {
            std::shared_ptr<Entity> b = std::make_shared<Bullet>(p->position, GetMousePosition());
            entityContainer.add(b);
        }

        p->update(delta);

        ClearBackground(GRAY);
        BeginDrawing();
            p->render();
        entityContainer.render();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

