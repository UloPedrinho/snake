#ifndef BOARD_HPP_
#define BOARD_HPP_

#include "helpers.hpp"
#include <vector>

class Board {
public:
  Board() {};
  Board(int width, int height, Cell init_value);
  void setup(int width, int height, Cell init_value);
  int getWidth() {return w;};
  int getHeight() {return h;};
  void mark_cell(Point point, Cell value);

  std::vector<std::vector<Cell>> getBoard() const;
private:
  int w;
  int h;
  std::vector<std::vector<Cell>> grid;
};

#endif
