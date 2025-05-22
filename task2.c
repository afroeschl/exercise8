/// @file
/// @brief Task2: function definitions

#include "task2.h" // struct Vec2d, struct Circle, struct BBox

/// @todo Include C standard library headers as needed

/// ====================================  Bounding Box
/// =================================================
/// @todo Implement the missing functions for bounding box as declared and
/// specified in task2.h

/// @todo Implement function 'bbox_scale'
struct BBox bbox_scale(const struct BBox *self, struct Vec2d org, double s) {
  struct BBox bbox = *self;
  bbox.min.x = org.x + (bbox.min.x - org.x) * s;
  bbox.min.y = org.y + (bbox.min.y - org.y) * s;
  bbox.max.x = org.x + (bbox.max.x - org.x) * s;
  bbox.max.y = org.y + (bbox.max.y - org.y) * s;

  return bbox;
  // use struct before BBox
}

/// @todo Implement function 'bbox_translate'
struct BBox bbox_translate(const struct BBox *self, struct Vec2d offset) {
  struct BBox bbox = *self;

  bbox.min.x += offset.x;
  bbox.min.y += offset.y;
  bbox.max.x += offset.x;
  bbox.max.y += offset.y;

  return bbox;
}

/// ====================================  Circle
/// ================================================
/// @todo Implement the missing functions for Circle as declared and specified
/// in task2.h

/// @todo Implement function 'circle_bbox'
struct BBox circle_bbox(const struct Circle *self) {
  struct Circle circle = *self;
  struct BBox bbox;

  bbox.min.x = circle.c.x - circle.r;
  bbox.min.y = circle.c.y - circle.r;
  bbox.max.x = circle.c.x + circle.r;
  bbox.max.y = circle.c.y + circle.r;

  return bbox;
}

/// @todo Implement function 'circle_scale'
struct Circle circle_scale(const struct Circle *self, struct Vec2d org,
                           double s) {
  struct Circle circle = *self;

  double dx = circle.c.x - org.x;
  double dy = circle.c.y - org.y;

  circle.c.x = org.x + dx * s;
  circle.c.y = org.y + dy * s;
  circle.r *= s;

  return circle;
}

/// @todo Implement function 'circle_rotate'
struct Circle circle_rotate(const struct Circle *self, struct Vec2d org,
                            double angle) {
  struct Circle circle = *self;

  double dx = circle.c.x - org.x;
  double dy = circle.c.y - org.y;

  circle.c.x = org.x + dx * cos(angle) - dy * sin(angle);
  circle.c.y = org.y + dx * sin(angle) + dy * cos(angle);

  return circle;
}

/// @todo Implement function 'circle_translate'
struct Circle circle_translate(const struct Circle *self, struct Vec2d offset) {
  struct Circle circle = *self;

  circle.c.x += offset.x;
  circle.c.y += offset.y;

  return circle;
}
