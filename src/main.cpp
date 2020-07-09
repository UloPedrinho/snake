#include "board.hpp"
#include "snake.hpp"
#include "debug.hpp"
#include "helpers.hpp"

int main()
{
  Board board(5,5,-1);

  Point a{1, 2};

  board.mark_cell(a, 1);
  board.mark_cell(Point{4, 4}, 5);
  debug_board_printBoard(board.getBoard());

  Snake snake(3, Point{3,3}, Direction::East);
  debug_snake_printPoints(snake.get());

  return 0;
}
