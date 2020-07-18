#include "helpers.hpp"

// elements helper functions
std::vector<Point> generateWall(int width, int height){
  std::vector<Point> wall;
  for (int i = 0; i < width; ++i) {
    wall.push_back({i, 0});
    wall.push_back({i, height-1});
  }
  for (int i = 0; i < height; ++i) {
    wall.push_back({0, i});
    wall.push_back({width-1,i});
  }
  return wall;
}
