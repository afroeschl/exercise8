/// @file
/// @brief Task3: structure and function declarations

#pragma once

#include "task2.h" // struct Vec2d, struct BBox, struct Circle

/// @brief Count the number of Circles fully contained inside a bounding box
/// @param box Bounding box
/// @param circles Array of Circles
/// @param size Length of the 'circles' array
/// @return Number of circles fully contained inside 'box'
unsigned int task3_count_inside(const struct BBox* box, const struct Circle circles[], unsigned int size);

/// @brief Generates the smallest bounding box containing a sequence of circles
/// @param circles Array of Circles
/// @param size Length of the 'circles' array (Assertion: size >= 1)
/// @return Smallest bounding box containing all circles 
struct BBox task3_common_bbox(const struct Circle circles[], unsigned int size);
