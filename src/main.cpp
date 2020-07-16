#include "game.hpp"
#include "helpers.hpp"
#include "debug.hpp"

int main()
{
  Board board;
  Snake snake;

  initBoard(board, 10, 10, Cell::Empty);

  putElementInBoard(board, {2,2}, Cell::Wall);
  putElementInBoard(board, {3,2}, Cell::Wall);
  putElementInBoard(board, {3,1}, Cell::Wall);

  initSnake(snake, 3, Direction::East);
  putElementsInBoard(board, snake.body, Cell::Snake_body);

  debug_printBoard(board.board);

  return 0;
}
