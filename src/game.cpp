#include "game.hpp"
#include <iostream>

Game::Game() {
  board.setup(10, 10, 0);


  window.create(sf::VideoMode(400,400), "snake", sf::Style::Resize); // FIXME: video mode and title ;;
  window.setFramerateLimit(60); // FIXME:  https://www.sfml-dev.org/tutorials/2.5/window-window.ph

  cell_points = cellsPoints(window.getSize(), sf::Vector2i {board.getWidth(),board.getHeight()});

}

void Game::run(){
  while(window.isOpen()){
    events();
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
  }
}

void Game::render() {
  // renderGrid(grid, window.getSize(), sf::Vector2i {board.getWidth(),board.getHeight()});
  renderGrid(grid, cell_points, sf::Vector2i {board.getWidth(),board.getHeight()});

}

void Game::draw() {
  window.draw(grid);
  // window.draw(cell_points);
}
