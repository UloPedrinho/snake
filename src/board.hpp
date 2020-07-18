#ifndef BOARD_HPP_
#define BOARD_HPP_

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
// board helper functions
void initBoard(Board& board, int width, int height, Cell value);
void cleanBoard(Board& board, Cell value);
void putElementInBoard(Board& board, const Point& position, Cell value);
void putElementsInBoard(Board& board, const std::vector<Point>& positions, Cell value);
void putElementsInBoard(Board& board, const std::deque<Point>& positions, Cell value);
bool collision(const Board& board, Point point);
Point getRandomEmptyPoint(Board& board);

#endif /* BOARD_HPP_ */
