/// @file
/// @brief Task2: function definitions

#include "task2.h" // struct Vec2d, struct Circle, struct BBox

/// @todo Include C standard library headers as needed

/// ====================================  Bounding Box
/// =================================================
/// @todo Implement the missing functions for bounding box as declared and
/// specified in task2.h

/// @todo Implement function 'bbox_scale'
struct BBox bbox_scale(const struct BBox* self, struct Vec2d org, double s) {
  struct BBox res = {};
  return res;
}

/// @todo Implement function 'bbox_translate'
struct BBox bbox_translate(const struct BBox* self, struct Vec2d offset) {
  struct BBox res = {};
  return res;
}

/// ====================================  Circle
/// ================================================
/// @todo Implement the missing functions for Circle as declared and specified
/// in task2.h

/// @todo Implement function 'circle_bbox'
struct BBox circle_bbox(const struct Circle* self) {
  struct BBox res = {};
  return res;
}

/// @todo Implement function 'circle_scale'
struct Circle circle_scale(const struct Circle* self, struct Vec2d org, double s) {
  struct Circle res = {};
  return res;
}

/// @todo Implement function 'circle_rotate'
struct Circle circle_rotate(const struct Circle* self, struct Vec2d org, double angle) {
  struct Circle res = {};
  return res;
}

/// @todo Implement function 'circle_translate'
struct Circle circle_translate(const struct Circle* self, struct Vec2d offset) {
  struct Circle res = {};
  return res;
}
