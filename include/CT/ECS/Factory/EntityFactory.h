#ifndef CT_ECS_ENTITY_FACTORY_H
#define CT_ECS_ENTITY_FACTORY_H

#include "CT/Common/Types.h"

namespace CT::ECS
{
    /**
    * Generate N count of entitites.
    *
    * @param int count
    *
    * @return EntityArray
    */
    EntityArray GenerateEntities(int count);

    /**
     * Destroy all the entities using the EXTERN variable 
     * defined in common/Globals.h
     */
    void DestroyEntities(EntityArray& entities, int count);
}

#endif // ECS_ENTITY_FACTORY_H
