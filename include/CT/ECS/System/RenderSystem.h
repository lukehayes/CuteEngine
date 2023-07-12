#ifndef ECS_RENDER_SYSTEM_H
#define ECS_RENDER_SYSTEM_H

#include "CT/ECS/System/System.h"

struct Color;

namespace CT::ECS
{
  /**
   * Base class for all systems.
   */
  class RenderSystem : public CT::ECS::System
  {
    public:

      /**
       * Update the system.
       *
       * @param double dt    Delta time.
       * @param Color  clearColor.
       * 
       * @return void.
       */
      void update(Color clearColor, double dt);
  };
}


#endif // ECS_SYSTEM_H
