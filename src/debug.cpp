#include "debug.hpp"

void debug_board_printBoard(const std::vector<std::vector<int>> &grid){
  for (const std::vector<int> &v : grid) {
    for (const int p : v)
      std::cout << p;
    std::cout << "\n";
  }
}

void debug_snake_printPoints(const std::deque<Point> &snake) {
  std::cout << "size: " << snake.size() << "\n";
  for(const Point &p : snake)
    std::cout << "(" << p.x << "," << p.y << ") ";
  std::cout << "\n";
}
