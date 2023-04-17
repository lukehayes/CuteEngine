add_library(CuteEngineLib
  # Engine Specific
  Game.cpp
  Globals.cpp

  # ECS Componets
  TransformComponent.cpp
  SoundComponent.cpp
  CollisionComponent.cpp

  # ECS Systems
  RenderSystem.cpp
  MoveSystem.cpp
)
