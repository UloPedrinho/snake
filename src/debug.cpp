#include "debug.hpp"
#include "helpers.hpp"
#include "board.hpp"

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

void debug_print_all(const std::vector<std::vector<int>> &grid, const std::deque<Point> &snake){
  // put snake into the board
  std::vector<std::vector<int>> g = grid;
  for(const Point& p : snake) {
    g[p.y][p.x] = 1;
  }

  debug_board_printBoard(g);
  std::cout  << "\n";
}

