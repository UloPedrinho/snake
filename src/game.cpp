#include "game.hpp"

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

// snake helper functions
void initSnake(Snake& snake, int init_size, int split_at, Direction direction, Point head_position){
  Point last_cell, current_cell;

  snake.init_size = init_size;
  snake.split_at = split_at;
  snake.direction = direction;
  // init snake head and body
  snake.head = head_position;
  last_cell = head_position;

  for (int i = 0; i < (snake.init_size-1); ++i) {
    if (snake.direction == Direction::North)
      current_cell = {last_cell.x, last_cell.y+1};
    else if (direction == Direction::South)
      current_cell = {last_cell.x, last_cell.y-1};
    else if (direction == Direction::East)
      current_cell = {last_cell.x-1, last_cell.y};
    else
      current_cell = {last_cell.x+1, last_cell.y};

    snake.body.push_back(current_cell);
    last_cell = current_cell;
  }
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
  if(snake.grow > 0)
    --snake.grow;
  else
    snake.body.pop_back();
}

void growSnake(Snake& snake, int length){
  snake.grow = length;
}

std::vector<Point> splitSnake(Snake& snake){
  std::vector<Point> tail;
  // poor vector slice. '-2' head and zero-based
  for (int i = snake.init_size-1; i < snake.body.size(); ++i)
    tail.push_back(snake.body[i]);
  snake.body.resize(snake.init_size-1);
  return tail;
}


// elements helper functions
std::vector<Point> generateWall(Board& board){
  std::vector<Point> wall;
  for (int i = 0; i < board.width; ++i) {
    wall.push_back({i, 0});
    wall.push_back({i, board.height-1});
  }
  for (int i = 0; i < board.height; ++i) {
    wall.push_back({0, i});
    wall.push_back({board.width-1,i});
  }
  return wall;
}

Point generateItemPoint(Board& board){
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
