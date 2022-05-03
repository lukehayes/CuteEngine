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
            this->position.x += 100 * dt;
            this->position.y += 100 * dt;
        }

        virtual void Draw() 
        {
            DrawRectangleLines(this->position.x,this->position.y,10,10, GREEN);
        }


private:

};



#endif
