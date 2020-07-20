#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "helpers.hpp"
#include <deque>
#include <vector>

struct Snake {
  int init_size;
  Direction direction;
  Point head;
  bool to_split {false};
  int split_at;
  int grow {0};
  std::deque<Point> body;
};

// snake helper functions
void initSnake(Snake& snake, int init_size, int split_at, Direction direction, Point head_position);
void moveSnake(Snake& snake);
void turnSnake(Snake& snake, Direction direction);
void growSnake(Snake& snake, int length);
std::vector<Point> splitSnake(Snake& snake);
#endif /* SNAKE_HPP_ */
