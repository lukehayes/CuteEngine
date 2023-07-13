#ifndef CT_SCENE_SCENETREE_E_H
#define CT_SCENE_SCENETREE_E_H

#include <map>
#include "CT/Scene/Scene.h"

namespace CT::Scene
{

  /**
   * Main SceneTree implementation.
   */
  class SceneTree
  {
  public:

   /**
    * Insert a scene into the scene tree.
    *
    * @param const CT::Scene::Scene.
    *
    * @return void.
    */
    void insert(const CT::Scene::Scene& scene);

   /**
    * Find a scene in the scene tree
    *
    * @param const CT::Scene::Scene.
    *
    * @return void.
    */
    bool find(const CT::Scene::Scene& scene);
  
  std::map<int, CT::Scene::Scene> tree;

  };
}
#endif // CT_SCENE_SCENE_H
