#include "CT/Scene/Scene.h"

#include <vector>
#include <cstdio>

namespace CT::Scene
{
  s   void 
    Scene::addChild(CT::Scene::Scene* child)
    {
      this->children.push_back(child);
      childrenCount++;
    }
}
