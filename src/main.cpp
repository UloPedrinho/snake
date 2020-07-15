#include "game.hpp"
#include "board.hpp"
#include "snake.hpp"
#include "debug.hpp"
#include "helpers.hpp"

int main()
{
  // Board board(10,5,0);
  // Snake snake(3, 7, Point{3,3}, Direction::East);

  Game game;
  game.run();

  return 0;
}
