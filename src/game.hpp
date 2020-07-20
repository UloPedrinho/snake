#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "helpers.hpp"
#include "board.hpp"
#include "snake.hpp"
#include <vector>
#include <deque>

// begin-debug
#include <iostream>
// end-debug


class Game
{
public:
  Game();
  void run();

private:
  void events();
  void update();
  void render();
  void draw();
private:
  Board board;
  Snake snake;

  sf::RenderWindow window;
  sf::View boardView;
  sf::View infoView;
  sf::FloatRect boardView_dimensions;
  sf::FloatRect infoView_dimensions;
  sf::VertexArray cells_position;
  sf::Vector2f cell_dimension;

  std::vector<Point> wall_points;
  sf::VertexArray wall_origins;
  sf::VertexArray food_origins;
  sf::VertexArray snake_body_origins;
  sf::Vertex snake_head_origin;

  std::vector<sf::RectangleShape> wall;
    std::vector<sf::RectangleShape> food;
  sf::RectangleShape snake_head_shape;
  std::vector<sf::RectangleShape> snake_body_shape;

  // FIXME: maybe move to another file
  int food_default_items;
  int food_current_items;

  // begin-debug
  sf::RectangleShape cell;
  std::vector<sf::RectangleShape> grid;

  sf::Text text;
  sf::Font font;
  // end-debug

};


#endif /* GAME_HPP */
