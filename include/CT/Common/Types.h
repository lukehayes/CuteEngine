#pragma once

/*============================================================
// Generic Includes
============================================================*/
#include "raylib.h" 
#include <array>
#include <vector>
#include <map>
#include <string>
#include <memory>

/*============================================================
// Framework Specific Includes
============================================================*/
#include "Game/Game.h"
#include "CT/Common/Constants.h"

/*============================================================
// ECS Specific Includes
============================================================*/
#include "CT/ECS/Component/Component.h"


/*============================================================
// Primitives
============================================================*/
using u8            = uint8_t;
using b8            = u8;
using s8            = int8_t;
using u16           = uint16_t;
using s16           = int16_t;
using u32           = uint32_t;
using s32           = int32_t;
using b32           = s32;
using u64           = uint64_t;
using s64           = int64_t;
using f32           = float;
using f64           = double;
using uchar         = unsigned int;
using str           = std::string;
using const_str_ref = const std::string&;
using const_str     = const char*;

/*============================================================
// Template Typedefs
============================================================*/
using Array2f       = std::array<f32,2>;
using Array3f       = std::array<f32,3>;
using Array4f       = std::array<f32,4>;
using Array8f       = std::array<f32,8>;
using VecFloat      = std::vector<float>;
using VecInt        = std::vector<size_t>;

/*============================================================
// Math Aliases
============================================================*/
using V2 = Vector2;


/*============================================================
// ECS Typedefs
============================================================*/
using EntityArray = std::array<std::array<CT::ECS::Component*, 4>, MAX_ENTITIES>;
using EntityVector = std::vector<std::array<CT::ECS::Component*, 4>>;

using EntityMap   = std::vector<std::map<std::string, CT::ECS::Component*>>;
/** EntityMap initialization example:
EntityMap entMap = {
    {
        {"Transform" , new ECS::TransformComponent(10,10,10,10, GREEN) }, 
        {"Sound",      new ECS::SoundComponent("FirstSound.mp4")}
    }
};
*/
