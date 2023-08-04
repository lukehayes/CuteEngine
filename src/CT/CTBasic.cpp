#include "CT/Core/CTBasic.h"

#include <stdio.h>

namespace CT::Core
{
    CTBasic::CTBasic()
        : position({0,0}),
          size({16,16}),
          color(PINK)
    {
        printf("CTBasic Constructed \n");
    }

	CTBasic::CTBasic(const Vector2& position, const Vector2& size, Color color)
        : position(position),
          size(size),
          color(color)
    {}

    CTBasic::~CTBasic()
    {
    }
}

