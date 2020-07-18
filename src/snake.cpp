#include "snake.hpp"

// snake helper functions
void initSnake(Snake& snake, int init_size, int split_at, Direction direction, Point head_position){
  Point last_cell, current_cell;

  snake.init_size = init_size;
  snake.split_at = split_at;
  snake.direction = direction;
  // init snake head and body
  snake.head = head_position;
  last_cell = head_position;

  for (int i = 0; i < (snake.init_size-1); ++i) {
    if (snake.direction == Direction::North)
      current_cell = {last_cell.x, last_cell.y+1};
    else if (direction == Direction::South)
      current_cell = {last_cell.x, last_cell.y-1};
    else if (direction == Direction::East)
      current_cell = {last_cell.x-1, last_cell.y};
    else
      current_cell = {last_cell.x+1, last_cell.y};

    snake.body.push_back(current_cell);
    last_cell = current_cell;
  }
}

void moveSnake(Snake& snake, Direction direction){
  Point head;
  Point old_head = snake.head;
  if (direction == Direction::North)
    head = {old_head.x, old_head.y-1};
  else if (direction == Direction::South)
    head = {old_head.x, old_head.y+1};
  else if (direction == Direction::East)
    head = {old_head.x+1, old_head.y};
  else
    head = {old_head.x-1, old_head.y};

  snake.head = head;
  snake.body.push_front(old_head);
  if(snake.grow > 0)
    --snake.grow;
  else
    snake.body.pop_back();
}

void growSnake(Snake& snake, int length){
  snake.grow = length;
}

std::vector<Point> splitSnake(Snake& snake){
  std::vector<Point> tail;
  // poor vector slice. '-2' head and zero-based
  for (int i = snake.init_size-1; i < snake.body.size(); ++i)
    tail.push_back(snake.body[i]);
  snake.body.resize(snake.init_size-1);
  return tail;
}
