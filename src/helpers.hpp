#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>

struct Point {
  int x;
  int y;
};

// TODO: move to game.hpp
enum class Cell {Empty, Wall, Snake_head, Snake_body, Food};
enum class Direction {North, South, East, West};

// cells functions
// FIXME: use type..etc  and only one function (?)
void generateCellsPosition(sf::VertexArray& cells_position, const sf::VertexArray& cells_origins, const std::vector<Point>& board_positions, Point board_size);
void generateCellsPosition(sf::VertexArray& cells_position, const sf::VertexArray& cells_origins, const std::deque<Point>& board_positions, Point board_size);

// renderers
void renderElement(sf::RectangleShape& cell, sf::Vector2f cell_position, sf::Vector2f cell_dimension, sf::Color color);
void renderElements(std::vector<sf::RectangleShape>& elements, sf::VertexArray& elements_position, sf::Vector2f element_dimension, sf::Color color);

// elements helper functionsa
std::vector<Point> generateWall(int width, int height);


#endif /* HELPERS_HPP */



