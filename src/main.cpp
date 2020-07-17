#include "game.hpp"
#include "helpers.hpp"
#include "debug.hpp"

int main()
{
  Board board;
  Snake snake;

  std::vector<Point> wall;

  initBoard(board, 30, 10, Cell::Empty);

  // begin-debug
  std::cout << "board.width.........: " << board.width << "\n";
  std::cout << "board.height........: " << board.height << "\n";
  std::cout << "board.board.size() m: " << board.board.size() << "\n";
  std::cout << "board.board.size() m: " << board.board[0].size() << "\n";
  // end-debug

  initSnake(snake, 3, Direction::East, {3,5});

  wall = generateWall(board);

  putElementInBoard(board, snake.head, Cell::Snake_head);
  putElementsInBoard(board, snake.body, Cell::Snake_body);
  putElementsInBoard(board, wall, Cell::Wall);

  debug_printBoard(board.board, board.width,board.height);
  std::cout << "\n";

  // moveSnake(snake, Direction::North);

  // cleanBoard(board, Cell::Empty);

  // putElementsInBoard(board, wall, Cell::Wall);
  // putElementInBoard(board, snake.head, Cell::Snake_head);
  // putElementsInBoard(board, snake.body, Cell::Snake_body);

  // putElementInBoard(board, generateItemPoint(board), Cell::Food);
  // putElementInBoard(board, generateItemPoint(board), Cell::Food);
  // putElementInBoard(board, generateItemPoint(board), Cell::Food);


  // debug_printBoard(board.board, board.width,board.height);


  return 0;
}
