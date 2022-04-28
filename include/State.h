#ifndef STATE_H
#define STATE_H


class State
{
public:
        State();
        ~State();

        /**
         * Update the next frame for this state.
         *
         * @param float dt    Delta time.
         */
        void Update(float dt);

private:

};




#endif
