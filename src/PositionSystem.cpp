#include "ECS/System/PositionSystem.h"
#include "ECS/Component/PositionComponent.h"
#include "ECS/World.h"
#include "Game.h"
#include <memory>

extern ECS::World world;
extern Game  game;

namespace ECS::System
{
    PositionSystem::PositionSystem() : System("Position") {}
    PositionSystem::~PositionSystem() {}

    void PositionSystem::update(float delta)
    {
        // TODO Brute force method of checking if an entity
        // has the required components - refactor.
        for(auto& entity : world.entities)
        {
            if(entityMeetsRequirements(entity))
            {
                auto pos = std::dynamic_pointer_cast<ECS::Component::PositionComponent>(entity.getComponent("Position"));

                pos->position.x += pos->velocity.x * pos->speed * delta;
                pos->position.y += pos->velocity.y * pos->speed * delta;

                if(pos->position.x < 0 || pos->position.x > game.width)
                {
                    pos->velocity.x = -pos->velocity.x;
                }

                if(pos->position.y < 0 || pos->position.y > game.height)
                {
                    pos->velocity.y = -pos->velocity.y;
                }
            }
        }
    }
}

