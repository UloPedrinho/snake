#include "helpers.hpp"
#include <iostream>
#include <vector>
#include <deque>

void debug_board_printBoard(const std::vector<std::vector<Cell>> &grid);
void debug_snake_printPoints(const std::deque<Point> &snake);
void debug_print_all(const std::vector<std::vector<Cell>> &grid, const std::deque<Point> &snake);
