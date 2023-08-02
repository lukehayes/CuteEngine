#include "CT/Scene/SceneTree.h"

#include <stdio.h>

namespace CT::Scene
{
    int
    SceneTree::insert(CT::Scene::Scene* scene)
    {
        this->tree.insert(std::pair(this->scene_id++, scene));
        this->scene_id++;

        return this->scene_id;
    }

    bool
    SceneTree::find(const CT::Scene::Scene& scene)
    {
        return false;
    }

    void
    SceneTree::remove(int scene_id)
    {
        if(this->tree.contains(scene_id))
        {
            this->tree.erase(scene_id);
            this->scene_id--;
        }else 
        {
            printf("That scene doesn't exists in the container");
        }
    }
}
