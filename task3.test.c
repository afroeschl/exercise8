/// @file
/// @brief Task3: tests

#include "task3.h" // task3_count_inside, task3_common_bbox
#include "task2.h" // struct Vec2d, struct BBox, struct Cirlce

#include "iue-num/numerics.h" // iuenum_isclose

#include <assert.h> // assert
#include <stdio.h> // printf

bool detail_isclose_vec2d(struct Vec2d a, struct Vec2d b) {
  if (!iuenum_isclose(a.x, b.x))
    return false;
  if (!iuenum_isclose(a.y, b.y))
    return false;
  return true;
}

bool detail_isclose_bbox(const struct BBox* a, const struct BBox* b) {
  if (!detail_isclose_vec2d(a->min, b->min))
    return false;
  if (!detail_isclose_vec2d(a->max, b->max))
    return false;
  return true;
}

int main() {

  { // testing 'task3_count_inside'
    struct Vec2d min = {-1.6, -0.6};
    struct Vec2d max = {3.6, 2.6};
    struct BBox box = {min, max};

    struct Circle c1 = {{0.0, 1.0}, 1.5};
    struct Circle c2 = {{1.0, 1.0}, 1.5};
    struct Circle c3 = {{2.0, 1.0}, 1.5};
    struct Circle c4 = {{3.0, 1.0}, 1.5};
    struct Circle c5 = {{4.0, 1.0}, 1.5};

    struct Circle circles[5] = {c1, c2, c3, c4, c5};

    unsigned int res = task3_count_inside(&box, circles, 5);

    assert(res == 3);
  }

  { // testing 'task3_common_bbox'

    struct Circle c1 = {{0.0, 1.0}, 1.5};
    struct Circle c2 = {{1.0, 1.0}, 1.5};
    struct Circle c3 = {{2.0, 1.0}, 1.5};

    struct Circle circles[3] = {c1, c2, c3};

    struct BBox res = task3_common_bbox(circles, 3);

    struct Vec2d exp_min = {-1.5, -0.5};
    struct Vec2d exp_max = {3.5, 2.5};
    struct BBox exp_box = {exp_min, exp_max};

    assert(detail_isclose_bbox(&res,&exp_box));
  }

  printf("task3.test.c: all asserts passed\n");

  return 0;
}
