#include "CT/Scene/SceneTree.h"

namespace CT::Scene
{
    SceneTree::SceneTree() 
        : scene_id(0)
    {}


    void
    SceneTree::insert(const CT::Scene::Scene& scene)
    {
        this->scene_id++;
    }

    bool
    SceneTree::find(const CT::Scene::Scene& scene)
    {
        return false;
    }

    void
    SceneTree::remove(int scene_id) {}
}
