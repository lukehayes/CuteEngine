#ifndef CT_SCENE_SCENE_H
#define CT_SCENE_SCENE_H

#include <map>

namespace CT::Scene
{

  /**
   * Base class for all scenes in the SceneTree.
   */
  class Scene
  {
  public:

    virtual void update(double dt) = 0;

    void addChild(CT::Scene::Scene* child)
    {
      this->children.insert(std::pair(childrenCount, child));
      childrenCount++;
    }

    std::map<int, CT::Scene::Scene*> children;
    inline static int childrenCount = 0;
  };
}
#endif // CT_SCENE_SCENE_H
