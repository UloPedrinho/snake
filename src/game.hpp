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
  sf::RenderWindow window;
  sf::View boardView;
  sf::View infoView;
  sf::FloatRect boardView_dimensions;
  sf::FloatRect infoView_dimensions;
  sf::VertexArray cells_position;

  Board board;
  Snake snake;

  std::vector<Point> wall_points;
  sf::VertexArray wall_origins;
  std::vector<sf::RectangleShape> wall;
  sf::Vector2f cell_dimension;

  // begin-debug
  sf::RectangleShape cell;

  std::vector<sf::RectangleShape> grid;

  sf::RectangleShape a;
  sf::RectangleShape b;
  sf::Text text;
  sf::Font font;
  // end-debug

};


#endif /* GAME_HPP */
