#ifndef ECS_RENDER_SYSTEM_H
#define ECS_RENDER_SYSTEM_H

struct Color;

namespace ECS
{
  /**
   * Base class for all systems.
   */
  class RenderSystem
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
