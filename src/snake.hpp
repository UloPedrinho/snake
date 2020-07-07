#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "helpers.hpp"
#include <vector>

class Snake {
public:
  // TODO: constructor
  void grow(int size);
  void decrease(int size);
  void generate(TODO);          // TODO arguments
private:
  int size;
  int growing {0};
  Point start_pos;
  Point end_pos;
  std::vector<Point> body;
};

#endif /* SNAKE_HPP */
