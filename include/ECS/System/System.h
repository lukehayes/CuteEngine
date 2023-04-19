#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "Common/Types.h"

namespace ECS
{
  /**
   * Base class for all systems.
   */
    class System
    {
    public:

    EntityArray* entities = nullptr;
  };
}


#endif // ECS_SYSTEM_H
