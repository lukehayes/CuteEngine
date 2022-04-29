#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"


class PlayState : public State
{
public:
        PlayState() { }
        ~PlayState() {}

        void Update(float dt) override
        {
            std::cout << "State Updating..." <<  std::endl;
        }

private:

};



#endif
