#ifndef GAME_HPP_
#define GAME_HPP_

#include "helpers.hpp"
#include <vector>
#include <deque>

struct Board {
  int width;
  int height;
  std::vector<std::vector<Cell>> board;
};

struct Snake {
  int init_size;
  Direction direction;
  Point head;
  std::deque<Point> body;
};

// board helper functions
void initBoard(Board& board, int width, int height, Cell value);
void putElementInBoard(Board& board, const Point& position, Cell value);
void putElementsInBoard(Board& board, const std::vector<Point>& positions, Cell value);
void putElementsInBoard(Board& board, const std::deque<Point>& positions, Cell value);

// snake helper functions
void initSnake(Snake& snake, int init_size, Direction direction);
void moveSnake(Snake& snake, Direction direction);
std::vector<Point> splitSnake(Snake& snake);

#endif /* GAME_HPP */
