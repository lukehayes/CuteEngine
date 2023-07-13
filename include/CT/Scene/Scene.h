#ifndef CT_SCENE_SCENE_H
#define CT_SCENE_SCENE_H

namespace CT::Scene
{

  /**
   * Base class for all scenes in the SceneTree.
   */
  class Scene
  {
  public:

    virtual void update(double dt) = 0;

  };
}
#endif // CT_SCENE_SCENE_H