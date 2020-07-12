#include "helpers.hpp"
#include <iostream>             // FIXME

void renderGrid(sf::VertexArray& grid, sf::VertexArray& cell_points, const sf::Vector2i board_size){

  grid.clear();

  grid.setPrimitiveType(sf::Lines);

  // x-lines
  for (int i = 0; i < board_size.x; ++i) {
    grid.append(sf::Vertex(cell_points[i]));
    grid.append(sf::Vertex(cell_points[board_size.x*(board_size.y-1)+i]));   // TODO HERE!!!!!
  }



  // float cell_w = window_size.x/board_size.x;
  // float cell_h = window_size.y/board_size.y;


  // grid.clear();

  // grid.setPrimitiveType(sf::Lines);

  // // x-lines
  // for (int i = 0; i < board_size.x; ++i) {
  //   grid.append(sf::Vertex(sf::Vector2f( cell_w*i, 0)));
  //   grid.append(sf::Vertex(sf::Vector2f( cell_w*i, window_size.y)));
  // }
  // // y-lines
  // for (int i = 0; i < board_size.y; ++i) {
  //   grid.append(sf::Vertex(sf::Vector2f(  0, cell_h*i)));
  //   grid.append(sf::Vertex(sf::Vector2f( window_size.x, cell_h*i)));
  // }
}

void renderSnake();             // TODO

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
