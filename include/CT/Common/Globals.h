#ifndef CT_GLOBALS_H
#define CT_GLOBALS_H

#include "Game/Game.h"
#include "Types.h"

#include "CT/Service/Container.h"

/**
 * Useful global variables, usually externs, are stored in here.
 */
/*============================================================
// GENERAL
============================================================*/
extern Game game;

/*============================================================
// ECS
============================================================*/
extern EntityArray entities;
extern EntityMap   entityMap;

/*============================================================
// ServiceContainer
============================================================*/
extern CT::Service::Container container;

#endif  // CT_GLOBALS_H
