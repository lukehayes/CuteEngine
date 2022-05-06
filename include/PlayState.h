#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include <memory>

class PlayState : public State
{
public:
        PlayState() : speed(GetRandomValue(1,50)){ Create(); }
        ~PlayState() {}

        void Create() override
        {
            game.add(this);
        }

        void Update(float dt) override
        {
            this->position.x += 1 * this->speed * dt;
            this->position.y += 1 * this->speed * dt;
        }

        virtual void Draw() 
        {
            DrawRectangleLines(this->position.x,this->position.y,10,10, GREEN);
        }


private:
        int speed = 1;

};



#endif
