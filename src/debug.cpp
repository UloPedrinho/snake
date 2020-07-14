#include "debug.hpp"
#include "helpers.hpp"
#include "board.hpp"

void debug_board_printBoard(const std::vector<std::vector<Cell>> &grid){
  for (int i=0; i < grid.size(); ++i) {
    for(int j=0; j < grid[0].size(); ++j)
      std::cout << static_cast<std::underlying_type<Cell>::type>(grid[j][i]);
    std::cout << "\n";
  }
    std::cout << "\n";


  // for (const std::vector<Cell> &v : grid) {
  //   for (const Cell p : v)
  //     std::cout << static_cast<std::underlying_type<Cell>::type>(p);
  //   std::cout << "\n\n";
  // }
}


// void debug_board_printBoard(const std::vector<std::vector<Cell>> &grid){
//   for (const std::vector<Cell> &v : grid) {
//     for (const Cell p : v)
//       std::cout << static_cast<std::underlying_type<Cell>::type>(p);
//     std::cout << "\n\n";
//   }
// }

void debug_snake_printPoints(const std::deque<Point> &snake) {
  std::cout << "size: " << snake.size() << "\n";
  for(const Point &p : snake)
    std::cout << "(" << p.x << "," << p.y << ") ";
  std::cout << "\n";
}

void debug_print_all(const std::vector<std::vector<Cell>> &grid, const std::deque<Point> &snake){
  // put snake into the board
  std::vector<std::vector<Cell>> g = grid;
  int c = 0;
  for(const Point& p : snake) {
    if (c == 0)
      g[p.y][p.x] = Cell::Head;
    else
      g[p.y][p.x] = Cell::Body;
  }

  debug_board_printBoard(g);
  std::cout  << "\n";
}
