#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

namespace ECS
{
  /**
   * Base class for all systems.
   */
  class System
  {
    public:

      /**
       * Update the system.
       *
       * @param double dt    Delta time.
       * 
       * @return void.
       */
      virtual void update(double dt) = 0;
  };
}


#endif // ECS_SYSTEM_H
