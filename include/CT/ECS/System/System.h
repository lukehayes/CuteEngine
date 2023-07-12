#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "CT/Common/Types.h"

namespace CT::ECS
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
