#include "board.hpp"

// class Board
Board::Board(int width, int height, Cell init_value) {
  setup(width,  height, init_value);
}
void Board::setup(int width, int height, Cell init_value) {
  w = width;
  h = height;
  grid.resize(h, std::vector<Cell> (w, init_value));
}
std::vector<std::vector<Cell>> Board::getBoard() const { return grid; }

void Board::mark_cell(Point p, Cell v) {
  grid[p.x][p.y] = v;
}
