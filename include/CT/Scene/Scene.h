/** @file  CT/Scene/Scene.h
 *
 * @brief A Scene represents a node inside a SceneTree.
 * @namespace CT::Scene.
 * @author LDH.
 */
#ifndef CT_SCENE_SCENE_H
#define CT_SCENE_SCENE_H

#include <vector>
#include "CT/Core/CTBasic.h"

namespace CT::Scene
{
  class Scene : public CT::Core::CTBasic
  {
  public:

    Scene();
    Scene(const Vector2& position, const Vector2& size, Color color);

    /**
    * Pure virtual update method. Updates once per frame.
    *
    * @param dt Delta time.
    */
    virtual void update(double dt) = 0;

    /**
    * Pure virtual render method. Updates once per frame.
    */
    virtual void render() = 0;

    /**
    * Add a scene as a child to this scene.
    *
    * @param child An instance of CT::Scene::Scene*.
    *
    * @return void.
    */
    void addChild(CT::Scene::Scene* child);
    
    /**
    * Get this scenes children amount.
    *
    * @return The number of chilren this scene has.
    */
    int getChildCount() const;


    std::vector<CT::Scene::Scene*> children;
  };
}
#endif // CT_SCENE_SCENE_H
