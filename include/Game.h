#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <memory>
#include "State.h"

/**
 * Singleton class that holds helpers that are beneficial to be accessed globally.
 */
class Game
{
public:
        Game();
        Game(int width, int height);
        ~Game();

        /**
         * Update to the next frame.
         *
         * @param float dt    Delta time.
         */
        void Update(float dt);

        /**
         * Add a State object to the container
         *
         * @param State* state
         */
        void addState(const std::shared_ptr<State>& state);


         int width = 800;
         int height = 600;;

private:
         std::vector<std::shared_ptr<State>> stateContainer;
};


#endif
