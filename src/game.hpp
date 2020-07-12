#include "board.hpp"
#include "snake.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "helpers.hpp"          // FIXME

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
  // Snake snake;
  sf::RenderWindow window;
  sf::VertexArray cell_points;

  sf::VertexArray grid;         // FIXME
};


