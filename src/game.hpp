#ifndef GAME_HPP_
#define GAME_HPP_

#include "helpers.hpp"
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>


struct Board {
  int width;
  int height;
  std::vector<std::vector<Cell>> board;
};

struct Snake {
  int init_size;
  Direction direction;
  Point head;
  //bool growing {false};
  int split_at;
  int grow {0};
  std::deque<Point> body;
};

// board helper functions
void initBoard(Board& board, int width, int height, Cell value);
void cleanBoard(Board& board, Cell value);
void putElementInBoard(Board& board, const Point& position, Cell value);
void putElementsInBoard(Board& board, const std::vector<Point>& positions, Cell value);
void putElementsInBoard(Board& board, const std::deque<Point>& positions, Cell value);
bool collision(const Board& board, const Snake& snake);

// snake helper functions
void initSnake(Snake& snake, int init_size, int split_at, Direction direction, Point head_position);
void moveSnake(Snake& snake, Direction direction);
void growSnake(Snake& snake, int length);
std::vector<Point> splitSnake(Snake& snake);

// elements helper functions
std::vector<Point> generateWall(Board& board);
Point generateItemPoint(Board& board);

#endif /* GAME_HPP */
