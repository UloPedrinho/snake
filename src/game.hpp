#include "board.hpp"
#include "snake.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "helpers.hpp"          // FIXME
#include "debug.hpp"            // FIXME: DELETEME


class Game {
public:
  Game();
  void run();
private:
  void events();
  void update();
  void draw();
  void render();
private:
  Board board;
  Snake snake;
  Food food;
  sf::RenderWindow window;
  sf::VertexArray cell_points;
  std::vector<sf::RectangleShape> snake_body;
  std::vector<sf::RectangleShape> walls;
  sf::VertexArray grid;         // FIXME
};


