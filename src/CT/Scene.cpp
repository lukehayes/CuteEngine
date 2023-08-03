#include "CT/Scene/Scene.h"

#include <vector>
#include <cstdio>

namespace CT::Scene
{
  void
  Scene::addChild(CT::Scene::Scene* child)
  {
    this->children.push_back(child);
  }

  int 
  Scene::getChildCount() const
  {
    return this->children.size();
  }
}
