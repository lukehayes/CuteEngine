add_library(CuteEngineLib SHARED
  # Engine Specific
  Globals.cpp

  # ECS Components
  TransformComponent.cpp
  SoundComponent.cpp
  CollisionComponent.cpp
  CollisionSystem.cpp
  TimerComponent.cpp
  SpriteComponent.cpp

  # ECS Systems
  RenderSystem.cpp
  MoveSystem.cpp
  TimerSystem.cpp

  # Scene
  SceneTree.cpp
)
