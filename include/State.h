#ifndef STATE_H
#define STATE_H

#include "Object.h"

class State : public Object
{
public:
        State() {}
        ~State() {}

        /**
         * Update the next frame for this state.
         *
         * @param float dt    Delta time.
         */
        virtual void Update(float dt) = 0;

        /**
         * Draw the next frame for this state.
         */
        virtual void Draw() = 0;

private:

};




#endif
