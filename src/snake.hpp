#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "helpers.hpp"
#include <deque>
#include <iostream>             // FIXME: deleteme
class Snake {
public:
  Snake () {};
  Snake(int initial_size, int full_size, Point initial_head_position, Direction initial_direction);
  void setup(int initial_size, int full_size, Point initial_head_position, Direction initial_direction);
  void grow(int size);
  void move(Direction dir);
  bool getSplitted() const;
  void toggleSplit();
  void split();
  void render();                // generate current snake body
  Direction getDirection() const {return direction;};
  std::deque<Point> getSnake() const { return body; };
private:
  int size;
  int init_size;
  int limit_size;
  int growing {0};
  bool splitted {false};
  Direction direction;
  std::deque<Point> body;
};
#endif /* SNAKE_HPP */
