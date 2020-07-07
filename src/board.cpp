#include "board.hpp"

// class Board
Board::Board(int width, int height, int init_value) {
  w = width;
  h = height;
  grid.resize(h, std::vector<int> (w));
  // TODO: init 
}
std::vector<std::vector<int>> Board::getBoard() const { return grid; }

void Board::mark_cell(Point p, int v) {
  grid[p.x][p.y] = v;
}
