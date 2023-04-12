#ifndef ECS_MOVE_SYSTEM_H
#define ECS_MOVE_SYSTEM_H


namespace ECS
{
    class MoveSystem
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
      void update(double dt);
    };
}



#endif // ECS_MOVE_SYSTEM_H
