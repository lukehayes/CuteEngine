#include "CT/Core/CTBasic.h"

#include <stdio.h>

namespace CT::Core
{
    CTBasic::CTBasic()
    : position({0,0}),
      size({16,16}),
      color(PINK),
      speed(GetRandomValue(10,200))
    {
        printf("CTBasic Constructed \n");
    }

    CTBasic::CTBasic(const Vector2& position, const Vector2& size, Color color)
    : position(position),
      size(size),
      color(color),
      speed(GetRandomValue(-400,400))
    {}

    CTBasic::~CTBasic()
    {
    }
}

