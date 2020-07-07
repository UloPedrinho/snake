#ifndef BOARD_HPP_
#define BOARD_HPP_

#include "helpers.hpp"
#include <vector>

class Board {
public:
  Board(int width, int height, int init_value);
  void mark_cell(Point point, int value);
  void unmark_cell(Point point, int value);
  std::vector<std::vector<int>> getBoard() const;
private:
  int w;
  int h;
  std::vector<std::vector<int>> grid;
};

#endif
