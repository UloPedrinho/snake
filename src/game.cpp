#include "game.hpp"
#include <iostream>

Game::Game() {
  // init game data
  board.setup(30, 30, Cell::Empty);
  snake.setup(3, 20, {5,5}, Direction::East);
  food.units = food.current = 3; // FIXME

  // create window
  window.create(sf::VideoMode(400,400), "snake", sf::Style::Resize); // FIXME: video mode and title ;;
  window.setFramerateLimit(2); // FIXME:  https://www.sfml-dev.org/tutorials/2.5/window-window.ph

  // generate cells points(top-left)
  cell_points = cellsPoints(window.getSize(), sf::Vector2i {board.getWidth(),board.getHeight()});

}

void Game::run(){
  while(window.isOpen()){
    events();
    update();
    render();
    window.clear(sf::Color::Black);
    draw();
    window.display();
  }
}

void Game::events() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window.close();

    if (event.type == sf::Event::KeyPressed) {
      switch (event.key.code) {
      case sf::Keyboard::Left: {
        if (snake.getDirection() != Direction::East)
          snake.move(Direction::West);
        break;
      }
      case sf::Keyboard::Right: {
        if (snake.getDirection() != Direction::West)
          snake.move(Direction::East);
        break;
      }
      case sf::Keyboard::Up: {
        if (snake.getDirection() != Direction::South)
          snake.move(Direction::North);
        break;
      }
      case sf::Keyboard::Down: {
        if (snake.getDirection() != Direction::North)
          snake.move(Direction::South);
        break;
      }
      // debug
      case sf::Keyboard::G: {
        snake.grow(1);
        break;
      }
      case sf::Keyboard::S: {
        snake.toggleSplit();
        break;
      }

      default:
        break;
      }
    }
  }
}

void Game::update() {
  std::deque<Point> old_snake = snake.getSnake();

  // TODO test collisions..etc
  snake.render();
  // put snake into board
  // FIXME: good solution?
  if (snake.getSplitted()) { // snake is to be splitted
    snake.split();
    board.putElement(old_snake, Cell::Wall);
  } else
    board.putElement(old_snake, Cell::Empty);

  // generate current snake


  board.putElement(snake.getSnake(), Cell::Body);

  // begin-DEBUG
  debug_board_printBoard(board.getBoard());
  // end-DEBUG
}

void Game::render() {
  renderGrid(grid, window.getSize(), sf::Vector2i {board.getWidth(),board.getHeight()});
  renderSnake(snake_body, cell_points, snake.getSnake(), sf::Vector2i {board.getWidth(),board.getHeight()});
}

void Game::draw() {
   window.draw(grid);
  for (int i = 0; i < snake_body.size(); ++i) {
    window.draw(snake_body[i]);
  }
  // window.draw(cell_points);
}
