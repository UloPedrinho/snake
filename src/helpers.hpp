#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <vector>

struct Point {
  int x;
  int y;
};


// TODO: move to game.hpp
enum class Cell {Empty, Wall, Snake_head, Snake_body, Food};
enum class Direction {North, South, East, West};

// elements helper functions
std::vector<Point> generateWall(int width, int height);

#endif /* HELPERS_HPP */
