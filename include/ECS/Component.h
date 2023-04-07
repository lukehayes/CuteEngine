#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

namespace ECS
{
  /**
   * Base class for all components.
   */
  class Component
  {
    public:

      /**
       * Update the component.
       *
       * @param double dt    Delta time.
       * 
       * @return void.
       */
      virtual void update(double dt) = 0;
  };
}

#endif // ECS_COMPONENT_H
