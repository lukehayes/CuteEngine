#ifndef CT_SCENE_SCENE_H
#define CT_SCENE_SCENE_H

#include <vector>

namespace CT::Scene
{
  /**
   * Base class for all scenes in the SceneTree.
   */
  class Scene
  {
  public:

    virtual void update(double dt) = 0;

    void addChild(CT::Scene::Scene* child);

    inline static int childrenCount = 0;

    std::vector<CT::Scene::Scene*> children;
  };
}
#endif // CT_SCENE_SCENE_H
