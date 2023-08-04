#include "CT/Scene/Scene.h"

#include <vector>

namespace CT::Scene
{
  Scene::Scene(Vector2& position, Vector2& size, Color color)
      : CT::Core::CTBasic(position, size, color)
  {}

  Scene::Scene()
    : CT::Core::CTBasic()
  {}

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
