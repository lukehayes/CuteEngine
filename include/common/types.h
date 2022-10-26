#pragma once

/*============================================================
// Generic Includes
============================================================*/
#include "raylib.h" 
#include <array>
#include <vector>
#include <string>
#include <memory>
#include <iostream>

/*============================================================
// Framework Specific Includes
============================================================*/
#include "Game.h"

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
using Array2f   =      std::array<f32,2>;
using Array3f   =      std::array<f32,3>;
using Array4f   =      std::array<f32,4>;
using Array8f   =      std::array<f32,8>;
using VecFloat  =      std::vector<float>;
using VecInt    =      std::vector<size_t>;

/*============================================================
// Math Aliases
============================================================*/
using V2        =      Vector2;
