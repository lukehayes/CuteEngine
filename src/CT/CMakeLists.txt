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

  # Assets
  Asset.cpp

  # Scene
  SceneTree.cpp
  Scene.cpp

  # Core
  CTBasic.cpp
)
