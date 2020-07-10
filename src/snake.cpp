#include "snake.hpp"

Snake::Snake(int initial_size, int full_size, Point initial_head_position, Direction initial_direction){
  size = initial_size;
  init_size = initial_size;
  full_size = limit_size;
  direction = initial_direction;
  // put head
  body.push_front(initial_head_position);
  // build body
  for (int i = 0; i < size-1; ++i) {
    if(direction == Direction::North){ // TODO: make helper function to not repeat code 'render()'
      body.push_back({body.back().x, body.back().y+1});
    } else if (direction == Direction::South){
      body.push_back({body.back().x, body.back().y-1});
    } else if (direction == Direction::West){
      body.push_back({body.back().x+1, body.back().y});
    } else if (direction == Direction::East){
      body.push_back({body.back().x-1, body.back().y});
    }
  }
}

void Snake::grow(int size){ growing += size; }
void Snake::move(Direction dir){ direction = dir; }
void Snake::split(){ body.resize(init_size); }
void Snake::render() {
  // head
  if(direction == Direction::North){
    body.push_front({body.front().x, body.front().y-1});
  } else if (direction == Direction::South){
    body.push_front({body.front().x, body.front().y+1});
  } else if (direction == Direction::West){
    body.push_front({body.front().x-1, body.front().y});
  } else if (direction == Direction::East){
    body.push_front({body.front().x+1, body.front().y});
  }
  size++;                       // body size grows

  // tail
  //  moves if growing equal to or lesser 0
  if(growing <= 0) {
    body.pop_back();            // remove last snake body cell
    size--;                     // body size decrease
    if (growing < 0 ) {         // remove one back cell
      body.pop_back();
      growing++;
      size--;                   // body size decrease
    }
  } else {
    growing--;
  }

  // TODO: cut tail (look notes in .org)
}
