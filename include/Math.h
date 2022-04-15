#ifndef RE_MATH_H
#define RE_MATH_H

#include <cmath>

/**
 * Static math helper functions.
 */
class Math
{
public:

    /**
     * Linear interpolation. Wrapper for std::lerp.
     *
     * @param T a;
     * @param T b;
     * @param T t;
     *
     * @return T;
     */
    template <class T>
    static T lerp(T a, T b, T t)
    {
        return std::lerp(a,b,t);
    }

};



#endif // RE_MATH_H
