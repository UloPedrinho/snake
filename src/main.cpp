#include "game.hpp"
#include "helpers.hpp"
#include "debug.hpp"

void cycle(Board& board, Snake& snake, std::vector<Point>& wall, Direction dir,int cycles);
void cycle(Board& board, Snake& snake, std::vector<Point>& wall, Direction dir,int cycles){
  std::vector<Point> tail;
  for (int i = 0; i < cycles; i++) {
    moveSnake(snake, dir);
    if ((snake.body.size() + 1) >= snake.split_at) {
      tail = splitSnake(snake);
      // putElementsInBoard(board, tail, Cell::Wall);
      wall.insert(wall.end(), tail.begin(), tail.end());
      snake.grow = 0;
      std::cout << "----- split : " << tail.size() << " -----" << "\n";
    }
    cleanBoard(board, Cell::Empty);
    putElementInBoard(board, snake.head, Cell::Snake_head);
    putElementsInBoard(board, snake.body, Cell::Snake_body);
    putElementsInBoard(board, wall, Cell::Wall);
    debug_printBoard(board.board, board.width, board.height);
  }
}


int main()
{
  Board board;
  Snake snake;

  std::vector<Point> wall;

  initBoard(board, 30, 10, Cell::Empty);
  initSnake(snake, 3, 15, Direction::East, {3,5});

  // begin-debug
  // std::cout << "board.width.........: " << board.width << "\n";
  // std::cout << "board.height........: " << board.height << "\n";
  // std::cout << "board.board.size() m: " << board.board.size() << "\n";
  // std::cout << "board.board.size() m: " << board.board[0].size() << "\n";
  // end-debug



  wall = generateWall(board);

  cycle(board, snake, wall, Direction::North, 3);
  growSnake(snake, 20);
  cycle(board, snake, wall, Direction::East, 5);
  cycle(board, snake, wall, Direction::South, 3);
  cycle(board, snake, wall, Direction::East, 5);
  growSnake(snake, 20);
  cycle(board, snake, wall, Direction::East, 5);
  cycle(board, snake, wall, Direction::North, 3);
  cycle(board, snake, wall, Direction::West, 5);
  // for (int i = 0; i < 3; ++i) {
  // moveSnake(snake, Direction::North);
  // cleanBoard(board, Cell::Empty);
  // putElementInBoard(board, snake.head, Cell::Snake_head);
  // putElementsInBoard(board, snake.body, Cell::Snake_body);
  // putElementsInBoard(board, wall, Cell::Wall);
  // debug_printBoard(board.board, board.width,board.height);
  // }

  // growSnake(snake, 3);

  // for (int i = 0; i < 4; ++i) {
  // moveSnake(snake, Direction::East);
  // cleanBoard(board, Cell::Empty);
  // putElementInBoard(board, snake.head, Cell::Snake_head);
  // putElementsInBoard(board, snake.body, Cell::Snake_body);
  // putElementsInBoard(board, wall, Cell::Wall);
  // debug_printBoard(board.board, board.width,board.height);
  // }

  // // putElementsInBoard(board, wall, Cell::Wall);
  // // putElementInBoard(board, snake.head, Cell::Snake_head);
  // // putElementsInBoard(board, snake.body, Cell::Snake_body);

  // putElementInBoard(board, generateItemPoint(board), Cell::Food);
  // putElementInBoard(board, generateItemPoint(board), Cell::Food);
  // putElementInBoard(board, generateItemPoint(board), Cell::Food);


  // // debug_printBoard(board.board, board.width,board.height);
  // cleanBoard(board, Cell::Empty);
  // putElementInBoard(board, snake.head, Cell::Snake_head);
  // putElementsInBoard(board, snake.body, Cell::Snake_body);
  // putElementsInBoard(board, wall, Cell::Wall);
  // putElementInBoard(board, generateItemPoint(board), Cell::Food);
  // putElementInBoard(board, generateItemPoint(board), Cell::Food);
  // putElementInBoard(board, generateItemPoint(board), Cell::Food);
  // debug_printBoard(board.board, board.width,board.height);

  return 0;
}
