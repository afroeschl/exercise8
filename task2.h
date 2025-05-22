/// @file
/// @brief Task3: Structure definitions and function declarations

#pragma once

#include <math.h>    // cos, sin
#include <stdbool.h> // bool, true, false

/// @note you can assume all of the pointer type parameters are valid pointers and not NULL

/// @brief Two-dimensional coordinate
struct Vec2d {
  double x; ///< first dimension
  double y; ///< second dimension
};

/// @brief Axis-aligned bounding box
struct BBox {
  struct Vec2d min; ///< coord of bottom left corner
  struct Vec2d max; ///< coord of top right corner
};

/// @brief Scales a bounding box (relative to a reference coordinate)
/// @param self Bounding box to operate on
/// @param org Reference coordinate
/// @param s Scaling factor
/// @return Scaled bounding box
struct BBox bbox_scale(const struct BBox* self, struct Vec2d org, double s);

/// @brief Translates a bounding box
/// @param self Bounding box to operate on
/// @param offset Translation vector
/// @return Translated bounding box
struct BBox bbox_translate(const struct BBox* self, struct Vec2d offset);

/// @brief Circle
struct Circle {
  struct Vec2d c; ///< coordinate of the center of the circle
  double r;       ///< radius of the circle
};

/// @brief Generates the minimum axis-aligned bounding box containing a circle
/// @param self Circle to operate on
/// @return Axis-aligned bounding box
struct BBox circle_bbox(const struct Circle* self);

/// @brief Scales the circle center (relative to a reference coordinate), and the radius with a scalar value
/// @param self Circle to operate on
/// @param org Reference coordinate
/// @param s Scaling factor
/// @return Scaled circle
struct Circle circle_scale(const struct Circle* self, struct Vec2d org, double s);

/// @brief Rotates the circle center (relative to a reference coordinate) counter clockwise
/// @param self Circle to operate on
/// @param org Reference coordinate
/// @param angle Rotation angle (in radians)
/// @return Rotated circle
struct Circle circle_rotate(const struct Circle* self, struct Vec2d org, double angle);

/// @brief Translates the circle center
/// @param self Circle to operate on
/// @param offset Translation vector
/// @return Translated circle
struct Circle circle_translate(const struct Circle* self, struct Vec2d offset);
