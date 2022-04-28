#ifndef GAME_H
#define GAME_H

#include <string>
#include <stack>
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
        void addState(const State& state);


         int width = 800;
         int height = 600;;

private:
         std::stack<State> stateContainer;
};


#endif
