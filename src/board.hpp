#ifndef BOARD_HPP_
#define BOARD_HPP_

#include "helpers.hpp"
#include <vector>
#include <deque>

class Board {
public:
  Board() {};
  Board(int width, int height, Cell init_value);
  void setup(int width, int height, Cell init_value);
  int getWidth() {return w;};
  int getHeight() {return h;};
  void putElement(std::deque<Point> element, Cell value);
  void putElement(std::vector<Point> element, Cell value);
  void putElement(Point element, Cell value);
  void mark_cell(Point point, Cell value);
  Cell getElementAt(Point point);
  std::vector<std::vector<Cell>> getBoard() const;
  std::vector<Point> getElementPoints(Cell element) const;
private:
  int w;
  int h;
  std::vector<std::vector<Cell>> grid;
};

#endif
