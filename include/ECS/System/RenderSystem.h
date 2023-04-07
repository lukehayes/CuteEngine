#ifndef ECS_RENDER_SYSTEM_H
#define ECS_RENDER_SYSTEM_H

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
       * 
       * @return void.
       */
      void update(double dt);
  };
}


#endif // ECS_SYSTEM_H
