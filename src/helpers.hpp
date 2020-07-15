#ifndef HELPERS_HPP_
#define HELPERS_HPP_
#include <SFML/Window.hpp>      // FIXME : repeating?
#include <SFML/Graphics.hpp>    // FIXME : repeating?
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

struct Point{
  int x;
  int y;
};

enum class Direction {
  North,
  South,
  East,
  West
};

enum class Cell{Empty, Wall, Head, Body, Grow, Split};

struct Items {
  int units;
  int current;
  Cell type;
  std::vector<Point> points;
};

// generate random elements
void generateRandomElement(Items& element, const std::vector<std::vector<Cell>> board, const sf::Vector2i board_size);

// draw functions
sf::VertexArray cellsPoints(const sf::Vector2u window_size, const sf::Vector2i board_size);
// render functions
void renderGrid(sf::VertexArray& grid, sf::Vector2u window_size, const sf::Vector2i board_size);
void renderSnake(std::vector<sf::RectangleShape>& body, const sf::VertexArray& origins, const std::deque<Point> snake, const sf::Vector2i board_size);
void renderElements(std::vector<sf::RectangleShape>& elements, const sf::VertexArray& origins,  const std::vector<Point> points, sf::Color color, const sf::Vector2i board_size);
#endif /* HELPERS_HPP */
