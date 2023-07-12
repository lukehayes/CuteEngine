#ifndef CT_GLOBALS_H
#define CT_GLOBALS_H

#include "CT/Game.h"
#include "Types.h"

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

#endif  // CT_GLOBALS_H
