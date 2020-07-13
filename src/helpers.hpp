#ifndef HELPERS_HPP_
#define HELPERS_HPP_
#include <SFML/Window.hpp>      // FIXME : repeating?
#include <SFML/Graphics.hpp>    // FIXME : repeating?
#include <vector>
#include <deque>

struct Point{
  int x;
  int y;
};

enum class Direction{North, South, East, West};

// draw functions
sf::VertexArray cellsPoints(const sf::Vector2u window_size, const sf::Vector2i board_size);

void renderGrid(sf::VertexArray& grid, sf::Vector2u window_size, const sf::Vector2i board_size);
void renderSnake(std::vector<sf::RectangleShape>& body, const sf::VertexArray& origins, const std::deque<Point> snake);


#endif /* HELPERS_HPP */
