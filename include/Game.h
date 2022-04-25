#ifndef GAME_H
#define GAME_H

#include <string>

/**
 * Singleton class that holds helpers that are beneficial to be accessed globally.
 */
class Game
{
public:
        Game();
        Game(int width, int height);
        ~Game();

         int width = 800;
         int height = 600;;

private:
};


#endif
