#include "game.hpp"

// board helper functions
void initBoard(Board& board, int width, int height, Cell value){
  board.width = width;
  board.height = height;
  board.board.resize(height, std::vector<Cell> (width, value));
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

// snake helper functions
void initSnake(Snake& snake, int init_size, Direction direction){
  snake.init_size = init_size;
  snake.direction = direction;
}

void moveSnake(Snake& snake, Direction direction){
  Point head;
  Point old_head = snake.head;
  if (direction == Direction::North)
    head = {old_head.x, old_head.y-1};
  else if (direction == Direction::South)
    head = {old_head.x, old_head.y+1};
  else if (direction == Direction::East)
    head = {old_head.x+1, old_head.y};
  else
    head = {old_head.x-1, old_head.y};

  snake.head = head;
  snake.body.push_front(old_head);
  snake.body.pop_back();
}
std::vector<Point> splitSnake(Snake& snake){
  std::vector<Point> tail;
  // poor vector slice. '-2' head and zero-based
  for (int i = snake.init_size-2; i < snake.body.size(); ++i)
    tail.push_back(snake.body[i]);
  snake.body.resize(snake.init_size);
  return tail;
}


