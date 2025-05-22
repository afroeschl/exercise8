/// @file
/// @brief Task2: tests

#include "task2.h" // struct Vec2d, struct BBox, struct Cirlce

#include "iue-num/numerics.h" // iuenum_isclose, iuenum_PI

#include <assert.h> // assert
#include <stdio.h>  // printf

bool detail_isclose_vec2d(struct Vec2d a, struct Vec2d b) {
  if (!iuenum_isclose(a.x, b.x))
    return false;
  if (!iuenum_isclose(a.y, b.y))
    return false;
  return true;
}

bool detail_isclose_bbox(const struct BBox *a, const struct BBox *b) {
  if (!detail_isclose_vec2d(a->min, b->min))
    return false;
  if (!detail_isclose_vec2d(a->max, b->max))
    return false;
  return true;
}

bool detail_isclose_circle(const struct Circle *a, const struct Circle *b) {
  if (!detail_isclose_vec2d(a->c, b->c))
    return false;
  if (!iuenum_isclose(a->r, b->r))
    return false;
  return true;
}

int main() {

  /// ======= BBox  =============================

  { // testing function 'bbox_scale'
    struct BBox box = {.min = {-10, 10}, .max = {10, 10}};
    struct Vec2d org = {-10, 0};
    box = bbox_scale(&box, org, 2);
    struct BBox expected = {.min = {-10, 20}, .max = {30, 20}};
    assert(detail_isclose_bbox(&box, &expected));
  }

  { // testing function 'bbox_translate'
    struct BBox box = {.min = {-10, 10}, .max = {10, 10}};
    struct Vec2d offset = {-10, 0};
    box = bbox_translate(&box, offset);
    struct BBox expected = {.min = {-20, 10}, .max = {0, 10}};
    assert(detail_isclose_bbox(&box, &expected));
  }

  /// ======= Circle  =============================

  { // testing function 'circle_bbox'
    struct Circle circle = {.c = {10, 10}, .r = 1};
    struct BBox box = {.min = {9, 9}, .max = {11, 11}};
    struct BBox cbox = circle_bbox(&circle);
    assert(detail_isclose_bbox(&cbox, &box));
  }

  { // testing function 'circle_scale'
    struct Circle circle = {.c = {10, 10}, .r = 1};
    struct Vec2d org = {0, 10};
    circle = circle_scale(&circle, org, 2);
    struct Circle expected = {{20, 10}, 2};
    assert(detail_isclose_circle(&circle, &expected));
  }

  { // testing function 'circle_rotate'
    struct Circle circle = {.c = {10, 10}, .r = 1};
    struct Vec2d org = {0, 10};
    circle = circle_rotate(&circle, org, iuenum_PI);
    struct Circle expected = {.c = {-10, 10}, .r = 1};
    assert(detail_isclose_circle(&circle, &expected));
  }

  { // testing function 'circle_translate'
    struct Circle circle = {.c = {10, 10}, .r = 1};
    struct Vec2d offset = {-20, -20};
    circle = circle_translate(&circle, offset);
    struct Circle expected = {.c = {-10, -10}, .r = 1};
    assert(detail_isclose_circle(&circle, &expected));
  }

  printf("task2.test.c: all asserts passed\n");

  return 0;
}
