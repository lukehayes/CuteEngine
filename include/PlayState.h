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
            std::cout << "Update" <<  std::endl;
        }

        virtual void Draw() 
        {
            DrawRectangleLines(10,10,10,10, GREEN);
        }


private:

};



#endif
