#include "CT/Scene/SceneTree.h"

namespace CT::Scene
{
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
