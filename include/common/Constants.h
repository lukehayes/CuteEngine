#ifndef CT_CONSTANTS_H
#define CT_CONSTANTS_H

/**
 * Useful contants are defined in this file.
 */
/*============================================================
// Window Constants
============================================================*/
constexpr int WINDOW_WIDTH  = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr const char* GAME_TITLE = "Game Title";

/*============================================================
// ECS Constants
============================================================*/
constexpr int MAX_ENTITIES              = 10;
constexpr int TRANSFORM_COMPONENT_INDEX = 0;
constexpr int SOUND_COMPONENT_INDEX     = 3;

#endif  // CT_CONSTANTS_H