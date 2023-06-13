add_library(CuteEngineLib
  # Engine Specific
  Game.cpp
  Globals.cpp

  # ECS Components
  TransformComponent.cpp
  SoundComponent.cpp
  CollisionComponent.cpp
  CollisionSystem.cpp
  TimerComponent.cpp

  # ECS Systems
  RenderSystem.cpp
  MoveSystem.cpp
)
