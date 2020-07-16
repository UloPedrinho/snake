#include "helpers.hpp"
#include <iostream>             // FIXME

std::vector<Point> getBoardLimitPoints(const sf::Vector2i board_size) {
  std::vector<Point> points;
  for (int i = 0; i < board_size.x; ++i) {
    points.push_back({i, 1});
    points.push_back({i, board_size.y - 1});
    std::cout << i << "\n";
  }
  for (int i = 0; i < board_size.y; ++i) {
    points.push_back({1, i});
    points.push_back({board_size.x - 1, i});
  }
  return points;
}

void generateRandomElement(Items& element, const std::vector<std::vector<Cell>> board, const sf::Vector2i board_size) {
  srand((unsigned) time(0));    //  FIXME here or ... in main..etc?
  int randomX;
  int randomY;
  int board_pos;
  int counter;
  int how_many = element.units-element.current;
  counter = 0;
  
  while(counter < how_many) {
    // random position
    // FIXME: adapted to BUG #2 
    randomX = (rand() % (board_size.x -1))+1;
    randomY = (rand() % (board_size.y -1))+1;

    // empty position?
    if (board[randomX][randomY] == Cell::Empty) {
      element.points.push_back({randomX, randomY});
      ++element.current;
      ++counter;
      // std::cout << "Element: "<< element.points.size() << "\n";
      // std::cout << " -- " << randomX << "," << randomY << "\n";
    }
  }
}

void renderGrid(sf::VertexArray& grid, sf::Vector2u window_size, const sf::Vector2i board_size){
  grid.clear();
  grid.setPrimitiveType(sf::Lines);

  float cell_w = window_size.x/board_size.x;
  float cell_h = window_size.y/board_size.y;


  // x-lines
  for (int i = 0; i < board_size.x; ++i) {
    grid.append(sf::Vertex(sf::Vector2f( cell_w*i, 0)));
    grid.append(sf::Vertex(sf::Vector2f( cell_w*i, window_size.y)));
  }
  // y-lines
  for (int i = 0; i < board_size.y; ++i) {
    grid.append(sf::Vertex(sf::Vector2f(  0, cell_h*i)));
    grid.append(sf::Vertex(sf::Vector2f( window_size.x, cell_h*i)));
  }
}

sf::VertexArray cellsPoints(const sf::Vector2u window_size, const sf::Vector2i board_size) {
  sf::VertexArray origins;
  origins.setPrimitiveType(sf::Points);

  float cell_w = window_size.x/board_size.x;
  float cell_h = window_size.y/board_size.y;

  for (int i = 0; i < board_size.x; ++i)
    for(int j = 0; j < board_size.y; j++ )
      origins.append(sf::Vertex(sf::Vector2f(cell_w*i,cell_h*j)));

  return origins;
}

void renderSnake(std::vector<sf::RectangleShape>& body, const sf::VertexArray& origins, const std::deque<Point> snake, const sf::Vector2i board_size) {
  sf::RectangleShape cell;
  int cell_pos;
  float cell_size = origins[0].position.x - origins[1].position.y; // FIXME: not clean solution. width and height the same??

  body.clear();

  for (int i  = 0 ; i < snake.size(); ++i) {

    cell_pos = snake[i].y + snake[i].x*board_size.x;  // FIXME reversed cordinates, snake class...etc

    cell.setSize(sf::Vector2f(cell_size, cell_size)); // FIXME
    cell.setPosition(origins[cell_pos].position);

    // cell.setOutlineColor(sf::Color::Magenta); // FIXME: use this?
    // cell.setOutlineThickness(5);

    if(i == 0)                  // snake head
      cell.setFillColor(sf::Color::Green);
    else
      cell.setFillColor(sf::Color::Blue);
    body.push_back(cell);
  }
}

void renderElements(std::vector<sf::RectangleShape>& elements, const sf::VertexArray& origins,  const std::vector<Point> points, sf::Color color,  const sf::Vector2i board_size){
  sf::RectangleShape cell;
  int cell_pos;
  float cell_size = origins[0].position.x - origins[1].position.y; // FIXME: refactor code,repeated in reders functions
  elements.clear();
  for (int i = 0; i < points.size(); ++i) {
    cell_pos = points[i].y +
               points[i].x *
                   board_size.x; // FIXME reversed cordinates, snake class...etc
    cell.setSize(sf::Vector2f(cell_size, cell_size)); // FIXME
    cell.setPosition(origins[cell_pos].position);
    cell.setFillColor(color);
    elements.push_back(cell);
  }
}

bool snakeOutBoard(const std::deque<Point> &snake, const std::vector<Point> board_limits) {
  // if (std::find(board_limits.begin(), board_limits.end(),snake.front()) !=  board_limits.end())
  //   return true;
  // return false;
  Point head = snake.front();
  std::cout << "h: " << head.x<<"," <<head.y  << "\n";

  for (const Point &p : board_limits) {
    if (p.x == head.x && p.y == head.y) {

      std::cout << "perry           ";
      std::cout << "h: " << head.x<<"," <<head.y  << "\n";
      return true;
    }
  }
  return false;
}
