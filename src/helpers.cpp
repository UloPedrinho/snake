#include "helpers.hpp"

// cells functions
void generateCellsPosition(sf::VertexArray& cells_position, const sf::VertexArray& cells_origins, const std::vector<Point>& board_positions, Point board_size){
  int index;

  cells_position.clear();
  for (int i = 0; i < board_positions.size(); ++i) {
    index = board_positions[i].x + board_positions[i].y*board_size.x;
    cells_position.append(cells_origins[index]);
  }
}
void generateCellsPosition(sf::VertexArray& cells_position, const sf::VertexArray& cells_origins, const std::deque<Point>& board_positions, Point board_size){
  int index;

  cells_position.clear();
  for (int i = 0; i < board_positions.size(); ++i) {
    index = board_positions[i].x + board_positions[i].y*board_size.x;
    cells_position.append(cells_origins[index]);
  }
}

// renderers
void renderElement(sf::RectangleShape& cell, sf::Vector2f cell_position, sf::Vector2f cell_dimension, sf::Color color){
  cell.setPosition(cell_position);
  cell.setSize(cell_dimension);
  cell.setFillColor(color);
}

void renderElements(std::vector<sf::RectangleShape>& elements, sf::VertexArray& elements_position, sf::Vector2f element_dimension, sf::Color color){
  sf::RectangleShape cell;

  elements.clear();
  for(int i = 0; i < elements_position.getVertexCount(); i++){
    cell.setPosition(elements_position[i].position);
    cell.setSize(element_dimension);
    cell.setFillColor(color);
    elements.push_back(cell);
  }
}

// elements helper functions
std::vector<Point> generateWall(int width, int height){
  std::vector<Point> wall;
  for (int i = 0; i < width; ++i) {
    wall.push_back({i, 0});
    wall.push_back({i, height-1});
  }
  for (int i = 0; i < height; ++i) {
    wall.push_back({0, i});
    wall.push_back({width-1,i});
  }
  return wall;
}
