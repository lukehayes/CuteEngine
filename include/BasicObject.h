#ifndef BASIC_OBJECT_H
#define BASIC_OBJECT_H

/**
 * Most if not all classes should inherti from this class.
 */
class BasicObject
{
    public:
        BasicObject();
        ~BasicObject();

        /**
         * Initialize an instance of this object in this method.
         */
        virtual void Create() = 0;

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
};


#endif
