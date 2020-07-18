#include "board.hpp"

// board helper functions
void initBoard(Board& board, int width, int height, Cell value){
  board.width = width;
  board.height = height;
  board.board.resize(width, std::vector<Cell> (height, value));
}

void putElementInBoard(Board& board, const Point& position, Cell value){
  board.board[position.x][position.y] = value;
}

void putElementsInBoard(Board& board, const std::vector<Point>& positions, Cell value){
  for (const Point& p : positions)
    putElementInBoard(board, p, value);
}
void putElementsInBoard(Board& board, const std::deque<Point>& positions, Cell value){
  for (const Point& p : positions)
    putElementInBoard(board, p, value);
}

void cleanBoard(Board& board, Cell value){
  for (int i = 0; i < board.width; ++i)
    for (int j = 0; j < board.height; ++j)
      board.board[i][j] = value;
}

bool collision(const Board& board, Point point){
  if (board.board[point.x][point.y] == Cell::Empty)
    return false;
  return true;
}

Point getRandomEmptyPoint(Board& board){
  srand((unsigned) time(0));
  int randomX;
  int randomY;

  while (true){
    randomX = rand() % board.width;
    randomY = rand() % board.height;
    if (board.board[randomX][randomY] == Cell::Empty)
      return {randomX, randomY};
  }
}
