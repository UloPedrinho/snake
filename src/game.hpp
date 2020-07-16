#ifndef GAME_HPP_
#define GAME_HPP_

#include "helpers.hpp"
#include <vector>
#include <deque>

enum class Cell {Empty, Wall, Snake_head, Snake_body, food};
enum class Direction {North, South, East, West};

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
void putElementInBoard(Board& board, Point& position, Cell value);
void putElementsInBoard(Board& board, std::vector<Point>& positions, Cell value);
void putElementsInBoard(Board& board, std::deque<Point>& positions, Cell value);

// snake helper functions
void initSnake(Snake& snake, int init_size, Direction direction);
void moveSnake(Snake& snake, Direction direction);
std::vector<Point> splitSnake(Snake& snake);

#endif /* GAME_HPP */
