#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "helpers.hpp"
#include <deque>

class Snake {
public:
  Snake(int initial_size, Point initial_head_position, Direction initial_direction);
  void grow(int size);
  void move(Direction dir);
  void split();
  void render();                // generate current snake body
  std::deque<Point> get() const { return body; };
private:
  int size;
  int init_size;
  int growing {0};
  Direction direction;
  std::deque<Point> body;
};
#endif /* SNAKE_HPP */
