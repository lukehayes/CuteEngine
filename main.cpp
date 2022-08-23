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

        bullets.update(delta);
        std::cout << bullets.entities.size() << std::endl;

        if(IsMouseButtonDown(0))
        {
            for(int i = 0; i <= 10000; i++)
            {
                std::shared_ptr<Bullet> b = std::make_shared<Bullet>(p->position, GetMousePosition());
                bullets.add(b);
            }
        }

        if(IsMouseButtonDown(1))
        {
            bullets.entities.clear();
            std::cout << "Cleared" << std::endl;
        }

        p->update(delta);

        ClearBackground(GRAY);
        BeginDrawing();
            p->render();
            bullets.render();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

