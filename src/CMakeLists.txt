add_library(RayEngineLib
  Game.cpp

  # ECS Componets
  TransformComponent.cpp
  SoundComponent.cpp

  # ECS Systems
  RenderSystem.cpp
  MoveSystem.cpp
)
