#include "game.hpp"
#include "helpers.hpp"
#include "debug.hpp"

int main()
{
  Board board;
  Snake snake;

  std::vector<Point> wall;
 
  initBoard(board, 10, 10, Cell::Empty);

  // putElementInBoard(board, {2,2}, Cell::Wall);
  // putElementInBoard(board, {3,2}, Cell::Wall);
  // putElementInBoard(board, {3,1}, Cell::Wall);

  initSnake(snake, 3, Direction::East, {5,5});

  wall = generateWall(board);

  putElementInBoard(board, snake.head, Cell::Snake_head);
  putElementsInBoard(board, snake.body, Cell::Snake_body);
  putElementsInBoard(board, wall, Cell::Wall);

  debug_printBoard(board.board);
  std::cout << "\n";

  moveSnake(snake, Direction::North);

  cleanBoard(board, Cell::Empty);

  putElementsInBoard(board, wall, Cell::Wall);
  putElementInBoard(board, snake.head, Cell::Snake_head);
  putElementsInBoard(board, snake.body, Cell::Snake_body);

  putElementInBoard(board, generateItemPoint(board), Cell::Food);
  putElementInBoard(board, generateItemPoint(board), Cell::Food);
  putElementInBoard(board, generateItemPoint(board), Cell::Food);


  debug_printBoard(board.board);


  return 0;
}
