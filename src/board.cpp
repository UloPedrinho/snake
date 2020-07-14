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

void Board::putElement(std::deque<Point> element, Cell value) {
  // TODO snake head diffenciate from body
  for (int i=0; i < element.size(); ++i) {
    mark_cell(element[i], value);
  }
}


std::vector<std::vector<Cell>> Board::getBoard() const { return grid; }

void Board::mark_cell(Point p, Cell v) {
  grid[p.x][p.y] = v;
}
