#ifndef CT_GLOBALS_H
#define CT_GLOBALS_H

#include "Game/Game.h"
#include "Types.h"

#include "CT/Factory/TextureFactory.h"

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
// TextureFactory
============================================================*/
extern CT::Factory::TextureFactory   textureFactory;

#endif  // CT_GLOBALS_H
