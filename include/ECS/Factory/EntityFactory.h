#ifndef ECS_ENTITY_FACTORY_H
#define ECS_ENTITY_FACTORY_H

#include <raylib.h>
#include <stdio.h>

#include "ECS/Component/Component.h"
#include "ECS/Component/TransformComponent.h"
#include "ECS/Component/SoundComponent.h"
#include "ECS/Component/CollisionComponent.h"
#include "ECS/Component/TimerComponent.h"
#include "ECS/Component/SpriteComponent.h"

#include "Common/Constants.h"
#include "Common/Globals.h"

#include "Factory/TextureFactory.h"

namespace ECS
{
    EntityArray GenerateEntities(int count)
    {
        CTFactory::TextureFactory textureFactory;

        printf("Initializing %i Entities \n", count);

        EntityArray entities;

        // Make sure all entity components are set to nullptr on initialization.
        for(auto ent : entities)
        {
            for(auto comp: ent)
            {
                comp = nullptr;
            }
        }

        /*============================================================
        // Entity Initializtion
        ============================================================*/
        /**
         * Entity Array Layout:
         *
         * [0] Transform Component - Always defined
         * [1] Sprite Component    - Can be null
         * [2] Collision Component - Can be null
         * [3] Timer Component     - Can be null - Possible Map
         * [4] Sound Component     - Can be null - Possible Map
         */
        for(int i = 0; i <= count - 1; i++)
        {
            Color color = {
                (unsigned char)GetRandomValue(10,255),
                (unsigned char)GetRandomValue(10,255),
                (unsigned char)GetRandomValue(10,255),
                (unsigned char)GetRandomValue(200,255)
            };

            int size = 10;


            entities.at(i)[TRANSFORM_COMPONENT_INDEX] = new ECS::TransformComponent(GetRandomValue(100,game.width), GetRandomValue(100,game.height), size, size, color);
            // entities.at(i)[SPRITE_COMPONENT_INDEX]    = GetRandomValue(0,1) ? new ECS::SpriteComponent(&textureFactory.bernie, 10) : nullptr;

            // TODO Implement textureFactory functionality.
            entities.at(i)[SPRITE_COMPONENT_INDEX]    = new ECS::SpriteComponent(CTAsset::Asset::getImage("bernie.png").c_str(), 2);
            entities.at(i)[COLLISION_COMPONENT_INDEX] = nullptr;
            entities.at(i)[TIMER_COMPONENT_INDEX]     = new ECS::TimerComponent();
            entities.at(i)[SOUND_COMPONENT_INDEX]     = nullptr;
        }

        return entities;
    }

    /**
     * Destroy all the entities using the EXTERN variable 
     * defined in common/Globals.h
     */
    void DestroyEntities(EntityArray& entities, int count)
    {
        // TODO Cheeky memory allocation cleanup.
        for(int i = 0; i <= count - 1; i++)
        {
            auto* transform_comp = dynamic_cast<ECS::TransformComponent*>(entities[i][TRANSFORM_COMPONENT_INDEX]);
            auto* sound_comp     = dynamic_cast<ECS::SoundComponent*>(entities[i][SOUND_COMPONENT_INDEX]);
            auto* collision_comp = dynamic_cast<ECS::CollisionComponent*>(entities[i][COLLISION_COMPONENT_INDEX]);
            auto* timer_comp     = dynamic_cast<ECS::TimerComponent*>(entities[i][TIMER_COMPONENT_INDEX]);
            auto* sprite_comp    = dynamic_cast<ECS::SpriteComponent*>(entities[i][SPRITE_COMPONENT_INDEX]);

            if(transform_comp){
                delete transform_comp;
                transform_comp = nullptr;
                printf("Deleted Transform Component %i\n", i);
            }

            if(sound_comp){
                delete sound_comp;
                sound_comp = nullptr;
                printf("Deleted Sound Component %i\n", i);
            }

            if(sprite_comp){
                delete sprite_comp;
                sprite_comp = nullptr;
                printf("Deleted Sprite Component %i\n", i);
            }

            if(collision_comp){
                delete collision_comp;
                collision_comp = nullptr;
                printf("Deleted Collision Component %i\n", i);
            }

            if(timer_comp){
                delete timer_comp;
                timer_comp = nullptr;
                printf("Deleted Timer Component %i\n", i);
            }

            printf("________ \n");
        }

        printf("All memory deleted \n");
    }
}

#endif // ECS_ENTITY_FACTORY_H
