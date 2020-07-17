#ifndef HELPERS_HPP
#define HELPERS_HPP

struct Point {
  int x;
  int y;
};


// TODO: move to game.hpp
enum class Cell {Empty, Wall, Snake_head, Snake_body, Food};
enum class Direction {North, South, East, West};


#endif /* HELPERS_HPP */
