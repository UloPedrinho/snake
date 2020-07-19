#include "game.hpp"

Game::Game(){
  int window_w = 400;           // FIXME
  int window_h = 400;           // FIXME

  sf::Vector2f view_origin(0.01f, 0.01f);
  sf::Vector2f boardView_size(window_w*0.75f, window_h*0.99f);
  sf::Vector2f infoView_size(window_w/4, window_h);
  int board_width;
  int board_height;

  // cell dimension alaways a square and fixed
  cell_dimension = sf::Vector2f(20.f, 20.f);

  board_width = boardView_size.x /cell_dimension.x;
  board_height = boardView_size.y /cell_dimension.y;
  initBoard(board, board_width, board_height, Cell::Empty);

  std::cout << board_width << "," << board_height << "\n";


  window.create(sf::VideoMode(window_w,window_h), "snake", sf::Style::Resize); // FIXME: video mode and title ;;
  window.setFramerateLimit(1); // FIXME:  https://www.sfml-dev.org/tutorials/2.5/window-window.ph

  // views
  boardView_dimensions = sf::FloatRect(view_origin, boardView_size);
  infoView_dimensions = sf::FloatRect(view_origin,infoView_size);
  boardView.reset(boardView_dimensions);
  infoView.reset(infoView_dimensions);
  boardView.setViewport(sf::FloatRect(0.01f, 0.01f, 0.75f, 0.99f));
  infoView.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 1.f));

  //boardView.zoom(1.1f);

  // cells
  cells_position.setPrimitiveType(sf::Points);


  // cells positions
  for (int i = 0; i < board.height; ++i) {
    for (int j = 0; j < board.width; ++j) {
      cells_position.append(sf::Vertex(sf::Vector2f(cell_dimension.x*j,cell_dimension.y*i)));
    }
  }

}

void Game::run(){
  while(window.isOpen()){
    events();
    update();
    render();
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

void Game::update(){


}


void Game::render(){
  grid.clear();
  for (int i = 0; i < cells_position.getVertexCount(); ++i) {
    // cell_pos = points[i].y +
    //            points[i].x *
    //                board_size.x; // FIXME reversed cordinates, snake
    //                class...etc

    cell.setSize(cell_dimension);
    cell.setPosition(cells_position[i].position);

    // cell.setSize(sf::Vector2f(cell_size, cell_size)); // FIXME
    // cell.setPosition(origins[cell_pos].position);

    if (i % 2 == 0)
      cell.setFillColor(sf::Color::Black);
    else
      cell.setFillColor(sf::Color::Blue);

    grid.push_back(cell);
  }

  a.setSize(cell_dimension);
  a.setPosition(cells_position[1].position);
  a.setFillColor(sf::Color::Red);

  b.setSize(cell_dimension);
  b.setPosition(cells_position[18].position);
  b.setFillColor(sf::Color::Red);
  

  // std::cout << grid.size() << "\n";
  // cell.setSize(cell_dimension);
  // cell.setPosition(40,40);

  // cell.setFillColor(sf::Color::Magenta);

  // a.setSize(sf::Vector2f(100.f, 100.f));
  // a.setPosition(50,50);
  // a.setFillColor(sf::Color::Magenta);
  // // a.setOutlineThickness(1.f);
  // a.setOutlineColor(sf::Color::Black);

  // b.setSize(sf::Vector2f(100.f, 100.f));
  // b.setPosition(150,49);

  // // b.setOutlineThickness(1.f);
  // b.setFillColor(sf::Color::Green);

  // begin-debug
  // r.setSize(sf::Vector2f(30,30));
  // r.setPosition(10,10);
  // b.setSize(sf::Vector2f(30,30));
  // b.setPosition(20,20);
  // r.setFillColor(sf::Color::Green);
  // b.setFillColor(sf::Color::Blue);
  // if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf"))
  //   std::cout << "BAD FONT" << "\n";
  // text.setFont(font);
  // text.setString("snake");
  // text.setCharacterSize(24);
  // text.setFillColor(sf::Color::Red);
  // text.setPosition(20.0, 20.0) ;
  // end-debug
}

void Game::draw(){
  window.clear(sf::Color::White);
  // window.setView(infoView);
  // window.draw(b);
  // window.draw(text);

  // window.draw(r);

  window.setView(boardView);
  for (int i = 0; i < grid.size(); ++i) {
    window.draw(grid[i]);
  }
  window.draw(a);
  window.draw(b);
}
