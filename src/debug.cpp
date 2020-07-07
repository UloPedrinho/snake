#include "debug.hpp"

void debug_board_printBoard(const std::vector<std::vector<int>> &grid){
  for (const std::vector<int> &v : grid) {
    for (const int p : v)
      std::cout << p;
    std::cout << "\n";
  }
}
