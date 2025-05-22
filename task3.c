/// @file
/// @brief Task3: function definitions

#include "task3.h" // task3_count_inside, task3_common_bbox
#include "task2.h" // struct Vec2d, struct BBox, struct Circle

/// @todo Include C standard library headers as needed

/// @todo Implement this function according the requirements specified in
/// task3.h
unsigned int task3_count_inside(const struct BBox *box,
                                const struct Circle circles[],
                                unsigned int size) {
  unsigned int count = 0;
  for (unsigned int i = 0; i < size; i++) {
    if (circles[i].c.x - circles[i].r >= box->min.x &&
        circles[i].c.x + circles[i].r <= box->max.x &&
        circles[i].c.y - circles[i].r >= box->min.y &&
        circles[i].c.y + circles[i].r <= box->max.y) {
      count++;
    }
  }
  return count;
}

/// @todo Implement this function according the requirements specified in
/// task3.h
struct BBox task3_common_bbox(const struct Circle circles[],
                              unsigned int size) {
  struct BBox res = {
      circles[0].c.x - circles[0].r, circles[0].c.y - circles[0].r,
      circles[0].c.x + circles[0].r, circles[0].c.y + circles[0].r};

  for (int i = 1; i < size; ++i) {
    if (circles[i].c.x - circles[i].r < res.min.x) {
      res.min.x = circles[i].c.x - circles[i].r;
    }
    if (circles[i].c.y - circles[i].r < res.min.y) {
      res.min.y = circles[i].c.y - circles[i].r;
    }
    if (circles[i].c.x + circles[i].r > res.max.x) {
      res.max.x = circles[i].c.x + circles[i].r;
    }
    if (circles[i].c.y + circles[i].r > res.max.y) {
      res.max.y = circles[i].c.y + circles[i].r;
    }
  }
  return res;
}
