#ifndef HELPERS_HPP_
#define HELPERS_HPP_
#include <SFML/Window.hpp>      // FIXME : repeating?
#include <SFML/Graphics.hpp>    // FIXME : repeating?


struct Point{
  int x;
  int y;
};

enum class Direction{North, South, East, West};

// draw functions
sf::VertexArray cellsPoints(const sf::Vector2u window_size, const sf::Vector2i board_size);

void renderGrid(sf::VertexArray& grid, sf::VertexArray& cell_points, const sf::Vector2i board_size);

#endif /* HELPERS_HPP */
