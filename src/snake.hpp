#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "helpers.hpp"
#include <deque>

class Snake {
public:
  // TODO: constructor
  void grow(int size);
  void decrease(int size);
  // generate current snake body
  void generate(TODO);          // TODO arguments
private:
  int size;
  int growing {0};
  Point start_pos;
  Point end_pos;
  std::deque<Point> body;
};

#endif /* SNAKE_HPP */
