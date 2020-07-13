#include "game.hpp"
#include <iostream>

Game::Game() {
  board.setup(30, 30, 0);
  snake.setup(7, 20, {14,14}, Direction::East);

  window.create(sf::VideoMode(400,400), "snake", sf::Style::Resize); // FIXME: video mode and title ;;
  window.setFramerateLimit(1); // FIXME:  https://www.sfml-dev.org/tutorials/2.5/window-window.ph

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
        snake.move(Direction::West);
        break;
      }
      case sf::Keyboard::Right: {
        snake.move(Direction::East);
        break;
      }
      case sf::Keyboard::Up: {
        snake.move(Direction::North);
        break;
      }
      case sf::Keyboard::Down: {
        snake.move(Direction::South);
        break;
      }
      default:
        break;
      }
    }
  }
}

void Game::update() {
  snake.render();
}

void Game::render() {
  //  renderGrid(grid, window.getSize(), sf::Vector2i {board.getWidth(),board.getHeight()});
  renderSnake(snake_body, cell_points, snake.getSnake());
}

void Game::draw() {
  //  window.draw(grid);
  for (int i = 0; i < snake_body.size(); ++i) {
    window.draw(snake_body[i]);
  }
  // window.draw(cell_points);
}
